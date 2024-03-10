#!/bin/bash
CHAR_TEMP_FILENAME="./chartemp.txt"
ASCII_TEMP_FILENAME="./temp.txt"
BIN_CHARSET_FILENAME="./charset.bin"

# Goto script directory
cd "$(dirname "$0")"

# Create temp ascii charset file with dummy header (two bytes)
echo "01010101" >> "$ASCII_TEMP_FILENAME"
echo "01010101" >> "$ASCII_TEMP_FILENAME"

for file in "./chars"/*
do
  if [ "$file" != "./chars/template.txt" ]
  then
    # Strip first two lines from file
    cat "$file" | tail -8 > "$CHAR_TEMP_FILENAME"

    # Strip last character from each line
    sed -i ".bck" -E 's/.$//' "$CHAR_TEMP_FILENAME"

    # Replace spaces with 0
    sed -i ".bck" -E 's/\ /0/g' "$CHAR_TEMP_FILENAME"

    # Replace X with 1
    sed -i ".bck" -E 's/X/1/g' "$CHAR_TEMP_FILENAME"
    rm "$CHAR_TEMP_FILENAME.bck"

    # Write content of new file into temp.txt
    echo "" >> "$ASCII_TEMP_FILENAME"
    echo "" >> "$ASCII_TEMP_FILENAME"
    echo "// $file" >> "$ASCII_TEMP_FILENAME"
    cat "$CHAR_TEMP_FILENAME" >> "$ASCII_TEMP_FILENAME"
    rm "$CHAR_TEMP_FILENAME"
  fi
done

# Keep only bits
cat "$ASCII_TEMP_FILENAME" | grep -E "\b[01]{8}\b" > "$ASCII_TEMP_FILENAME".bits.txt
rm "$ASCII_TEMP_FILENAME"

# Remove new lines
cat "$ASCII_TEMP_FILENAME".bits.txt | tr -d '\n' > "$ASCII_TEMP_FILENAME".monoline.txt
rm "$ASCII_TEMP_FILENAME".bits.txt

# Convert to binary format
cat "$ASCII_TEMP_FILENAME".monoline.txt | perl -lape '$_=pack"(B*)",@F' > "$BIN_CHARSET_FILENAME"
rm "$ASCII_TEMP_FILENAME".monoline.txt

# Remove last byte
truncate -s -1 "$BIN_CHARSET_FILENAME"
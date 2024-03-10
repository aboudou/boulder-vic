#!/bin/bash

BASE2_DIAMOND="00111001" # "D" char, code 57
BASE2_WALL="00111010"    # "W" char, code 58
BASE2_ROCK="00111011"    # "R" char, code 59
BASE2_BG="00111100"      # " " char, code 60
BASE2_FILLER="00111101"  # "-" char, code 61
BASE2_PLAYER="00111111"  # "P" char, code 63

# Goto script directory
cd "$(dirname "$0")"

for file in "./levels"/*.txt
do
    BIN_FILENAME=`echo "$file" | sed 's/txt/bin/' | sed 's/\/levels//'`
    ASCII_FILENAME="./levels/ascii.tmp"
    SCRATCH_FILE="./levels/temp.tmp"

    # Create temp ascii charset file with dummy header (two bytes)
    echo "01010101" >> "$ASCII_FILENAME"
    echo "01010101" >> "$ASCII_FILENAME"

    # Strip first two lines from file
    cat "$file" | tail -23 > "$SCRATCH_FILE"

    # Strip last character from each line
    sed -i ".bck" -E 's/.$//' "$SCRATCH_FILE"

    # Replace "D" with $BASE2_DIAMOND
    sed -i ".bck" -E "s/D/$BASE2_DIAMOND/g" "$SCRATCH_FILE"

    # Replace "D" with $BASE2_DIAMOND
    sed -i ".bck" -E "s/W/$BASE2_WALL/g" "$SCRATCH_FILE"

    # Replace "D" with $BASE2_DIAMOND
    sed -i ".bck" -E "s/R/$BASE2_ROCK/g" "$SCRATCH_FILE"

    # Replace "D" with $BASE2_DIAMOND
    sed -i ".bck" -E "s/\ /$BASE2_BG/g" "$SCRATCH_FILE"

    # Replace "D" with $BASE2_DIAMOND
    sed -i ".bck" -E "s/-/$BASE2_FILLER/g" "$SCRATCH_FILE"

    # Replace "D" with $BASE2_DIAMOND
    sed -i ".bck" -E "s/P/$BASE2_PLAYER/g" "$SCRATCH_FILE"
    rm "$SCRATCH_FILE.bck"

    cat "$SCRATCH_FILE" >> "$ASCII_FILENAME"
    rm "$SCRATCH_FILE"

    # Remove new lines
    cat "$ASCII_FILENAME" | tr -d '\n' > "$ASCII_FILENAME".monoline
    rm "$ASCII_FILENAME"

    # Convert to binary format
    cat "$ASCII_FILENAME".monoline | perl -lape '$_=pack"(B*)",@F' > "$BIN_FILENAME"
    rm "$ASCII_FILENAME".monoline

    # Remove last byte
    truncate -s -1 "$BIN_FILENAME"
done

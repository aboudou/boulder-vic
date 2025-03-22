#!/bin/bash

# Alphabet
BASE2_A="10000001"     # "A" char, code 129
BASE2_B="10000010"     # "B" char, code 130
BASE2_C="10000011"     # "C" char, code 131
BASE2_D="10000100"     # "D" char, code 132
BASE2_E="10000101"     # "E" char, code 133
BASE2_F="10000110"     # "F" char, code 134
BASE2_G="10000111"     # "G" char, code 135
BASE2_H="10001000"     # "H" char, code 136
BASE2_I="10001001"     # "I" char, code 137
BASE2_J="10001010"     # "J" char, code 138
BASE2_K="10001011"     # "K" char, code 139
BASE2_L="10001100"     # "L" char, code 140
BASE2_M="10001101"     # "M" char, code 141
BASE2_N="10001110"     # "N" char, code 142
BASE2_O="10001111"     # "O" char, code 143
BASE2_P="10010000"     # "P" char, code 144
BASE2_Q="10010001"     # "Q" char, code 145
BASE2_R="10010010"     # "R" char, code 146
BASE2_S="10010011"     # "S" char, code 147
BASE2_T="10010100"     # "T" char, code 148
BASE2_U="10010101"     # "U" char, code 149
BASE2_V="10010110"     # "V" char, code 150
BASE2_W="10010111"     # "W" char, code 151
BASE2_X="10011000"     # "X" char, code 152
BASE2_Y="10011001"     # "Y" char, code 153
BASE2_Z="10011010"     # "Z" char, code 154

# Numbers
BASE2_0="10110000"     # "0" char, code 176
BASE2_1="10110001"     # "1" char, code 177
BASE2_2="10110010"     # "2" char, code 178
BASE2_3="10110011"     # "3" char, code 179
BASE2_4="10110100"     # "4" char, code 180
BASE2_5="10110101"     # "5" char, code 181
BASE2_6="10110110"     # "6" char, code 182
BASE2_7="10110111"     # "7" char, code 183
BASE2_8="10111000"     # "8" char, code 184
BASE2_9="10111001"     # "9" char, code 185

# Special characters
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

    # Replace "W" with $BASE2_WALL
    sed -i ".bck" -E "s/W/$BASE2_WALL/g" "$SCRATCH_FILE"

    # Replace "R" with $BASE2_ROCK
    sed -i ".bck" -E "s/R/$BASE2_ROCK/g" "$SCRATCH_FILE"

    # Replace " " with $BASE2_BG
    sed -i ".bck" -E "s/\ /$BASE2_BG/g" "$SCRATCH_FILE"

    # Replace "-" with $BASE2_FILLER
    sed -i ".bck" -E "s/-/$BASE2_FILLER/g" "$SCRATCH_FILE"

    # Replace "P" with $BASE2_PLAYER
    sed -i ".bck" -E "s/P/$BASE2_PLAYER/g" "$SCRATCH_FILE"

    # Replace "a" with $BASE2_A
    sed -i ".bck" -E "s/a/$BASE2_A/g" "$SCRATCH_FILE"

    # Replace "b" with $BASE2_B
    sed -i ".bck" -E "s/b/$BASE2_B/g" "$SCRATCH_FILE"

    # Replace "c" with $BASE2_C
    sed -i ".bck" -E "s/c/$BASE2_C/g" "$SCRATCH_FILE"

    # Replace "d" with $BASE2_D
    sed -i ".bck" -E "s/d/$BASE2_D/g" "$SCRATCH_FILE"

    # Replace "e" with $BASE2_E
    sed -i ".bck" -E "s/e/$BASE2_E/g" "$SCRATCH_FILE"

    # Replace "f" with $BASE2_F
    sed -i ".bck" -E "s/f/$BASE2_F/g" "$SCRATCH_FILE"

    # Replace "g" with $BASE2_G
    sed -i ".bck" -E "s/g/$BASE2_G/g" "$SCRATCH_FILE"

    # Replace "h" with $BASE2_H
    sed -i ".bck" -E "s/h/$BASE2_H/g" "$SCRATCH_FILE"

    # Replace "i" with $BASE2_I
    sed -i ".bck" -E "s/i/$BASE2_I/g" "$SCRATCH_FILE"

    # Replace "j" with $BASE2_J
    sed -i ".bck" -E "s/j/$BASE2_J/g" "$SCRATCH_FILE"

    # Replace "k" with $BASE2_K
    sed -i ".bck" -E "s/k/$BASE2_K/g" "$SCRATCH_FILE"

    # Replace "l" with $BASE2_L
    sed -i ".bck" -E "s/l/$BASE2_L/g" "$SCRATCH_FILE"

    # Replace "m" with $BASE2_M
    sed -i ".bck" -E "s/m/$BASE2_M/g" "$SCRATCH_FILE"

    # Replace "n" with $BASE2_N
    sed -i ".bck" -E "s/n/$BASE2_N/g" "$SCRATCH_FILE"

    # Replace "o" with $BASE2_O
    sed -i ".bck" -E "s/o/$BASE2_O/g" "$SCRATCH_FILE"

    # Replace "p" with $BASE2_P
    sed -i ".bck" -E "s/p/$BASE2_P/g" "$SCRATCH_FILE"

    # Replace "q" with $BASE2_Q
    sed -i ".bck" -E "s/q/$BASE2_Q/g" "$SCRATCH_FILE"

    # Replace "r" with $BASE2_R
    sed -i ".bck" -E "s/r/$BASE2_R/g" "$SCRATCH_FILE"

    # Replace "s" with $BASE2_S
    sed -i ".bck" -E "s/s/$BASE2_S/g" "$SCRATCH_FILE"

    # Replace "t" with $BASE2_T
    sed -i ".bck" -E "s/t/$BASE2_T/g" "$SCRATCH_FILE"

    # Replace "u" with $BASE2_U
    sed -i ".bck" -E "s/u/$BASE2_U/g" "$SCRATCH_FILE"

    # Replace "v" with $BASE2_V
    sed -i ".bck" -E "s/v/$BASE2_V/g" "$SCRATCH_FILE"

    # Replace "w" with $BASE2_W
    sed -i ".bck" -E "s/w/$BASE2_W/g" "$SCRATCH_FILE"

    # Replace "x" with $BASE2_X
    sed -i ".bck" -E "s/x/$BASE2_X/g" "$SCRATCH_FILE"

    # Replace "y" with $BASE2_Y
    sed -i ".bck" -E "s/y/$BASE2_Y/g" "$SCRATCH_FILE"

    # Replace "z" with $BASE2_Z
    sed -i ".bck" -E "s/z/$BASE2_Z/g" "$SCRATCH_FILE"

    # Replace "Ø" with $BASE2_0
    sed -i ".bck" -E "s/Ø/$BASE2_0/g" "$SCRATCH_FILE"

    # Replace "|" with $BASE2_1
    sed -i ".bck" -E "s/\|/$BASE2_1/g" "$SCRATCH_FILE"

    # Replace "2" with $BASE2_2
    sed -i ".bck" -E "s/2/$BASE2_2/g" "$SCRATCH_FILE"

    # Replace "3" with $BASE2_3
    sed -i ".bck" -E "s/3/$BASE2_3/g" "$SCRATCH_FILE"

    # Replace "4" with $BASE2_4
    sed -i ".bck" -E "s/4/$BASE2_4/g" "$SCRATCH_FILE"

    # Replace "5" with $BASE2_5
    sed -i ".bck" -E "s/5/$BASE2_5/g" "$SCRATCH_FILE"

    # Replace "6" with $BASE2_6
    sed -i ".bck" -E "s/6/$BASE2_6/g" "$SCRATCH_FILE"

    # Replace "7" with $BASE2_7
    sed -i ".bck" -E "s/7/$BASE2_7/g" "$SCRATCH_FILE"

    # Replace "8" with $BASE2_8
    sed -i ".bck" -E "s/8/$BASE2_8/g" "$SCRATCH_FILE"

    # Replace "9" with $BASE2_9
    sed -i ".bck" -E "s/9/$BASE2_9/g" "$SCRATCH_FILE"

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

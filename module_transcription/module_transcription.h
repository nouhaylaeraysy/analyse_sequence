#include <string.h>
#include <stdio.h>
#include <ctype.h>
#ifndef COLORS
#include "../lib/colors.h"
#endif

int valid_sequence(char *sequence) {

    int is_valid = 1;
    int length = strlen(sequence);

    // check if our sequence is divisible on three
    if (length % 3 != 0) {
        printf("%sSequence is invalid, length is %d, please enter a valid sequence %s\n", RED, length, RESET);
        return 0;
    }

    // check if is valid DNA
    for (int i = 0; sequence[i] != '\0' && sequence[i] != '\n' &&  sequence[i] != '\r'; ++i) {
        char c = toupper(sequence[i]);  // Convert all to uppercase

        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            is_valid = 0;
            break;
        }
    }
    if(is_valid == 0){
        return 0;
    }

    // check if is VALID sequence 'ATG'
    if (
            (toupper(sequence[0]) == 'A') &&
            (toupper(sequence[1]) == 'T') &&
            (toupper(sequence[2]) == 'G')
            ) {
        return 1;
    } else {
        printf("%s Codon code is invalid, please enter a sequence starting with ATG %s\n", RED, RESET);
        return 0;
    }
}
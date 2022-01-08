#include "../lib/utils.h"
#include "../lib/constants.h"
#include "score_similaire.h"

int main(int argc, char *argv[]) {
    char *filePath1;
    char *filePath2;
    char *sequence1;
    char *sequence2;

    get_path_from_user(&filePath1, "Please entre a valid codon sequence 1: ");
    get_path_from_user(&filePath2, "Please entre a valid codon sequence 2: ");
    extract_sequence(filePath1, &sequence1);
    extract_sequence(filePath2, &sequence2);


    // condition which forces the equality of size of the two sequences
    if(strlen(sequence1) != strlen(sequence2)) {
        printf("\033[0;31m");
        printf("The sequences are not the same size");
        printf("\033[0m");
        return 0;
    }
    char score[strlen(sequence1)];
    printf("\n 0:hydrophiles , 1:hydrophobes , -:différents\r");

    // loop which calculates the similarity scores
    for (int i = 0; i < strlen(sequence1) && sequence1[i] != '\0' && sequence1[i] != '\n'; i++) {
        char codon1[2];
        sprintf(codon1, "%.*s", 1, sequence1 + i);
        char codon2[2];
        sprintf(codon2, "%.*s", 1, sequence2 + i);

        // If codon1 and codon2 are not empty, compare the two. In_array allows to check if the value of the codons are in the arrays of polar or nonpolar amino acids
        // If both are non-polar, the score is 1, if they are polar, the score is 0
        // Otherwise the two are different, we will have a - at score

        if (strcmp(codon1, "") != 0  && strcmp(codon2, "") != 0 ) {
            if (in_array(Ap, 9, codon1) && in_array(Ap, 9, codon2)) {
                score[i] = '1';
            } else if (in_array(Po, 9, codon1) && in_array(Po, 10, codon2)) {
                score[i] = '0';
            } else {
                score[i] = '-';
            }
        }
    }
    printf("%s\r", sequence1);
    printf("%s\r", sequence2);
    printf("%s", score);

    return 0;
}
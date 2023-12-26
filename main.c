#include <stdio.h>
#include <stdlib.h>
#include "./format_args.c"
#include "./remove_invalid.c"

#include "./calculate_syllables.c"

#include "./rand.c"

#include "./node.c"
#include "./create_sigil.c"

#include "./print_syllables.c"
#include "./print_sigil.c"
#include "./draw_sigil.c"

int main(int argc, char** argv) {

    if (argc < 2) {
        fprintf(stderr, "Invalid argument!");
        return 1;
    }

    printf("\nWill Received: ");

    char* str = formatArgs(argc, argv);

    str = removeInvalid(str);

    str = calcSyllables(str);

    srand(hash(str));

    printSyllables(str);

    struct node* head = createSigil(str);

    printSigil(head);

    drawSigil(head);
}
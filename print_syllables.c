#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define genColor() rand() % 6 + 1

bool colorsUsed[6];

void printSyllables(char* str) {

    for (int i = 0; i < 7; i++)
        colorsUsed[i] = false;

    printf("\n\nInterpreting syllables: (");

    int syllableCount = 0;

    int initColor = genColor();

    printf("\e[0;3%im", initColor);
    colorsUsed[initColor] = true;

    int acc = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            acc++;
            int color = genColor();
            while (colorsUsed[color])
                color = genColor();
            printf("\e[0;3%im ", color);
            colorsUsed[color] = true;
            syllableCount++;
        } else {
            acc = (acc + (str[i] - 'A')) % 25;
            printf("%c", (((str[i] - 'B') + acc) % 25) + 'B');
        }
    }
    printf("\e[0m)");
}
#include <stdbool.h>

// Remove invalid characters from the string (duplicates and vowels).
char* removeInvalid(char* str) {
    int strLength = 0;
    while (str[++strLength]);

    bool charUsed[25];

    for (int i = 0; i < 25; i++) charUsed[i] = 0;

    char* out = malloc(strLength);
    int finalSize = 0;
    int letterCount = 0;
    for (int i = 0; str[i]; i++) {

        // Convert lowercase letters to capital letters
        if (str[i] >= 'b' && str[i] <= 'z')
            str[i] -= ('a' - 'A');

        // If the character is a letter other than A and not a duplicate, add it to out.
        if (str[i] >= 'B' && str[i] <= 'Z') {
            if (!charUsed[str[i] - 'B']) {
                out[finalSize] = str[i];
                finalSize++;

                // if (str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U')
                charUsed[str[i] - 'B'] = true;
            }
            letterCount++;
            if (letterCount >= 19) {
                for (int i = 0; i < 25; i++) charUsed[i] = 0;
                letterCount = 0;
            }
        }
    }
    // Add a null terminator to the string and resize it to its proper length

    out[finalSize] = 0;
    out = realloc(out, finalSize + 1);
    return out;
}
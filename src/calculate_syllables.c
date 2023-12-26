char* calcSyllables(char* str) {
    
    int strSize = 0;
    while (str[++strSize]);

    char* out = malloc(strSize);
    for (int i = 0; i < strSize; i++)
        out[i] = 0;
    
    int acc = 0;
    int sizeIncrease = 0;
    for (int i = 0; str[i]; i++) {
        out[i + sizeIncrease] = str[i];
        acc += str[i] - 'B';
        if (acc >= 31 && str[i + 1]) {
            acc = 0;
            sizeIncrease++;
            strSize++;
            out = realloc(out, strSize);
            out[i + sizeIncrease] = ' ';
        }
    }

    out[strSize] = 0;

    return out;
}
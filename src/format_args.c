
// Format the (int, char**) that we receive as program arguments into a more usable (char*).
char* formatArgs(int argc, char** argv) {
    int size = 0;
    char* allArgs = (char*) malloc(1);

    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);

        int currentSize = 0;
        while (argv[i][++currentSize]);

        allArgs = realloc(allArgs, size + currentSize);

        for (int j = 0; argv[i][j]; j++) {
            allArgs[size + j] = argv[i][j];
        }
        
        size += currentSize;
    }
    allArgs[size] = 0;
    return allArgs;
}
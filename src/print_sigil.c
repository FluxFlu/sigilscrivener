void printSigil(Node* node) {
    printf("\n\n");
    while (node) {
        if (node->x == -1) {
            switch (node->y) {
                case '#':
                    printf("[]");
                    break;
                case 'O':
                    printf("O");
                    break;
                case '<':
                    printf("<");
                    break;
                case '|':
                    printf("|");
                    break;
                case '^':
                    printf("<|");
                    break;
                default:
                    printf("ERROR: INVALID NUMBER [%i]", node->y);
            }
        } else {
            printf("(%i, %i)", node->x, node->y);
        }
        printf(" ");
        node = node->next;
    }
}
Node head;

void handleChar(Node* node, char c, int graphSize) {
    c -= 'B';
    c = c % (graphSize * 3);
    node->x = c % graphSize + 1;
    node->y = ~~(c / graphSize) + 1;
}

int graphSize;

Node* createSigil(char* str) {

    int syllableCount = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ' ') syllableCount++;

    graphSize = 3 + (syllableCount >= 5 ? ~~(syllableCount / 4) : 0);


    head.x = -1;
    head.y = syllableCount >= 5 ? '#' : 'O';

    Node* next = (Node*) malloc(sizeof(Node));

    head.next = next;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            // printf("%s ", "|>");
            next->x = -1;
            next->y = '^';
        } else {
            handleChar(next, str[i], graphSize);
            if (str[i + 1] != 0 && str[i + 1] != ' ') {
                handleChar(next, str[i + 1], graphSize);
                i++;
            }
            // printf("(%i, %i)", next->x, next->y);
        }
        if (str[i + 1]) {
            Node* swap = (Node*) malloc(sizeof(Node));
            next->next = swap;
            next = swap;
        }
    }

    Node* last = (Node*) malloc(sizeof(Node));
    last->next = NULL;
    last->x = -1;
    last->y = syllableCount >= 8 ? '<' : '|';
    
    next->next = last;

    return &head;
}
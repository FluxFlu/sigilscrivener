#include "./geometry/draw_line.c"

void drawSigil(Node* node) {

    // Create a file and open it in write mode.
    FILE *fptr = fopen("sigil.pbm", "w");

    // Create an empty image to draw on.
    int canvasSize = graphSize * overallSize;

    fprintf(fptr, "P1 %i %i ", canvasSize, canvasSize);
    bool* canvas[canvasSize];
    for (int x = 0; x < canvasSize; x++) {
        canvas[x] = (bool*)malloc(sizeof(bool) * canvasSize);
        for (int y = 0; y < canvasSize; y++) {
            canvas[x][y] = 0;
        }
    }

    int lastPosX = 0;
    int lastPosY = 0;
    int posX = 0;
    int posY = 0;

    int drawOverCircleX = -1;
    int drawOverCircleY = -1;

    while (node) {
        if (node->x == -1) {
            switch (node->y) {
                case '#':
                    // printf("[]");
                    break;
                case 'O':
                    drawCircle(canvas, scale(4), calculatePosition(posX), calculatePosition(posY), scale(25.5), true);
                    drawOverCircleX = posX;
                    drawOverCircleY = posY;
                    break;
                case '<':
                    // printf("<");
                    break;
                case '|':
                    // printf("|");
                    break;
                case '^':
                    // printf("<|");
                    break;
                default:
                    printf("ERROR: INVALID NUMBER [%i]", node->y);
            }
        } else {
            lastPosX = posX;
            lastPosY = posY;
            posX = (posX + node->x) % graphSize;
            posY = (posY + node->y) % graphSize;
            drawLine(canvas, canvasSize, scale(4),
                calculatePosition(lastPosX),
                calculatePosition(lastPosY),
                calculatePosition(posX),
                calculatePosition(posY)
            );
            // for (int i = 0; i < )
            // printf("[%i, %i]", posX, posY);
        }
        printf(" ");
        node = node->next;
    }

    drawCircle(canvas, scale(4), calculatePosition(drawOverCircleX), calculatePosition(drawOverCircleY), scale(21.5), false);

    for (int x = 0; x < canvasSize; x++) {
        for (int y = 0; y < canvasSize; y++) {
            fprintf(fptr, "%c", canvas[x][y] ? '1' : '0');
        }
    }

    // Close the file
    fclose(fptr); 
}
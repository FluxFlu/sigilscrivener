typedef struct point {
    int x;
    int y;
} Point;

typedef struct line {
    Point* contents;
    int size;
} Line;
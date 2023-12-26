 /*
  * All grid-shape algorithms
  * are courtesy of Red Blob Games
  * at redblobgames.com
  *
  * This file's code can be found at https://www.redblobgames.com/grids/line-drawing/
  */

#include <stdlib.h>
#include <math.h>
#include "./point.c"

int max(int x, int y) {
    if (x > y)
        return x;
    return y;
}

int diagonal_distance(Point p0, Point p1) {
    int dx = p1.x - p0.x;
    int dy = p1.y - p0.y;
    return max(abs(dx), abs(dy));
}

float lerp(float start, float end, float t) {
    return start * (1.0 - t) + t * end;
}

Point lerp_point(Point p0, Point p1, float t) {
    return (Point){.x = lerp(p0.x, p1.x, t),
                   .y = lerp(p0.y, p1.y, t)};
}

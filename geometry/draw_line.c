 /*
  * All grid-shape algorithms
  * are courtesy of Red Blob Games
  * at redblobgames.com
  *
  * This file's code can be found at https://www.redblobgames.com/grids/line-drawing/
  */

#include "./lerp.c"
#include "./draw_circle.c"
#include "./size.c"

Line line(Point p0, Point p1) {
    Point* points = (Point*)malloc(sizeof(Point));
    double N = diagonal_distance(p0, p1);
    int size = 0;

    for (int step = 0; step <= N; step++) {
        double t = N == 0 ? 0.0 : step / N;
        points = (Point*)realloc(points, sizeof(Point) * ++size);
        points[size - 1] = lerp_point(p0, p1, t);
    }
    Line returnValue = {.contents = points, .size = size};
    return returnValue;
}

void drawLine(bool** canvas, int canvasSize, int weight, int fromPosX, int fromPosY, int posX, int posY) {
    Point p0 = {.x = fromPosX, .y = fromPosY};
    Point p1 = {.x = posX, .y = posY};

    Line lineToDraw = line(p0, p1);
    
    for (int i = 0; i < lineToDraw.size; i++) {
        Point point = lineToDraw.contents[i];
        drawCircle(canvas, scale(4), point.x, point.y, scale(2.5), true);
        // for (int x = -weight; x <= weight; x++) {
        //     int xToDraw = point.x + x;
        //     if (xToDraw > 0 && xToDraw < canvasSize)
        //         for (int y = -weight; y <= weight; y++) {
        //             int yToDraw = point.y + y;
        //             if (yToDraw > 0 && yToDraw < canvasSize)
        //                 canvas[xToDraw][yToDraw] = true;
        //         }
        // }
    }
}
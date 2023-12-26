 /*
  * All grid-shape algorithms
  * are courtesy of Red Blob Games
  * at redblobgames.com
  *
  * This file's code can be found at https://www.redblobgames.com/grids/circle-drawing/
  */

bool inside_circle(Point center, Point tile, float radius) {
    float dx = center.x - tile.x,
          dy = center.y - tile.y;
    float distance_squared = dx*dx + dy*dy;
    return distance_squared <= radius*radius;
}

void drawCircle(bool** canvas, int weight, int centerX, int centerY, float radius, bool paintWith) {
    Point center = {.x = centerX, .y = centerY};

    int top    =  ceil(center.y - radius);
    int bottom = floor(center.y + radius);
    int left   =  ceil(center.x - radius);
    int right  = floor(center.x + radius);

    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            if (inside_circle(center, (Point){.x = x, .y = y}, radius)) {
                // for (int i = -weight; i <= weight; i++) {
                    // int xToDraw = x + i;
                    // for (int j = -weight; j <= weight; j++) {
                        // int yToDraw = y + j;
                        canvas[x][y] = paintWith;
                    // }
                // }
            }
        }
    }
}
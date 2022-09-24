#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "u.h"
#include "vector.h"

typedef struct {
    ivec2 lowerLeftPoint;
    int height;
    int width;
} Rectangle;

int checkCollision(Rectangle* rect1, Rectangle* rect2) {
    if (rect1->lowerLeftPoint.x <= rect2->lowerLeftPoint.x + rect2->width &&
    rect1->lowerLeftPoint.x + rect1->width >= rect2->lowerLeftPoint.x &&
     rect1->lowerLeftPoint.y <= rect2->lowerLeftPoint.y + rect2->height &&
      rect1->lowerLeftPoint.y + rect1->height >= rect2->lowerLeftPoint.y) {
        return 1;
      }

    return 0;
}

#endif

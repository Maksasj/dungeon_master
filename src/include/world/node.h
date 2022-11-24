#ifndef _NODE_H_
#define _NODE_H_

#include "../types.h"
#include <stdlib.h>

typedef struct Node {
    i8 vertex;
    struct Node* next;
} Node;

Node* createNode(i8 _vertex);

#endif

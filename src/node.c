#include "include/world/node.h"

Node* createNode(i8 _vertex) {
    Node* node = malloc(sizeof(Node));

    node->vertex = _vertex;
    node->next = NULL;

    return node;
}

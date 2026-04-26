#ifndef NODE_H
#define NODE_H

#include "resident.h"

struct Node {
    Resident data;
    Node* next;
};

#endif
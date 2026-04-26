#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    void insertEnd(Resident r);
    void displayAll();
    int countResidents();

    Node* getHead();

    ~LinkedList();
};

#endif
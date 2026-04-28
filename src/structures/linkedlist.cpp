#include "linkedlist.h"
#include "node.h"
#include "linkedlist.h"

// Constructor
LinkedList::LinkedList() {
    head = nullptr;
}

// Insert at end
void LinkedList::insertEnd(Resident r) {
    Node* newNode = new Node;
    newNode->data = r;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }
}

// Return head pointer
Node* LinkedList::getHead() {
    return head;
}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
}
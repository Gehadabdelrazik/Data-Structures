#include "linkedlist.h"
#include "node.h"
#include <iostream>
#include <iomanip>
using namespace std;


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
// Display all residents in table format
void LinkedList::displayAll() {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
        return;
    }

    cout << left
         << setw(15) << "Resident ID"
         << setw(8)  << "Age"
         << setw(18) << "Transport"
         << setw(15) << "Distance"
         << setw(15) << "Factor"
         << setw(15) << "Days/Month"
         << endl;

    cout << string(86, '-') << endl;

    Node* current = head;

    while (current != nullptr) {
        Resident r = current->data;

        cout << left
             << setw(15) << r.ResidentID
             << setw(8)  << r.Age
             << setw(18) << r.ModeOfTransport
             << setw(15) << r.DailyDistance
             << setw(15) << r.CarbonEmissionFactor
             << setw(15) << r.AverageDayPerMonth
             << endl;

        current = current->next;
    }
}
// Count total residents in the linked list
int LinkedList::countResidents() {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
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
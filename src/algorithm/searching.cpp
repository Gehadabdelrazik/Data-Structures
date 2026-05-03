#include "searching.h"
#include <iostream>

using namespace std;

// =====================
// ARRAY SEARCHING
// =====================

int linearSearchArrayByID(Resident arr[], int size, string id) {
    for (int i = 0; i < size; i++) {
        if (arr[i].ResidentID == id) {
            return i;
        }
    }
    return -1;
}

int linearSearchArrayByAge(Resident arr[], int size, int age) {
    for (int i = 0; i < size; i++) {
        if (arr[i].Age == age) {
            return i;
        }
    }
    return -1;
}

// NEW REQUIRED SEARCHES

void searchArrayByAgeGroup(Resident arr[], int size, int minAge, int maxAge) {
    cout << "\n[Array] Age Group (" << minAge << "-" << maxAge << "): ";
    for (int i = 0; i < size; i++) {
        if (arr[i].Age >= minAge && arr[i].Age <= maxAge) {
            cout << arr[i].ResidentID << " ";
        }
    }
    cout << endl;
}

void searchArrayByTransport(Resident arr[], int size, string mode) {
    cout << "\n[Array] Transport (" << mode << "): ";
    for (int i = 0; i < size; i++) {
        if (arr[i].ModeOfTransport == mode) {
            cout << arr[i].ResidentID << " ";
        }
    }
    cout << endl;
}

void searchArrayByDistance(Resident arr[], int size, double minDistance) {
    cout << "\n[Array] Distance > " << minDistance << ": ";
    for (int i = 0; i < size; i++) {
        if (arr[i].DailyDistance > minDistance) {
            cout << arr[i].ResidentID << " ";
        }
    }
    cout << endl;
}

// =====================
// LINKED LIST SEARCHING
// =====================

Node* linearSearchListByID(Node* head, string id) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data.ResidentID == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

Node* linearSearchListByAge(Node* head, int age) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data.Age == age) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// NEW REQUIRED SEARCHES

void searchLinkedListByAgeGroup(Node* head, int minAge, int maxAge) {
    cout << "\n[Linked List] Age Group (" << minAge << "-" << maxAge << "): ";
    Node* current = head;

    while (current != nullptr) {
        if (current->data.Age >= minAge && current->data.Age <= maxAge) {
            cout << current->data.ResidentID << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void searchLinkedListByTransport(Node* head, string mode) {
    cout << "\n[Linked List] Transport (" << mode << "): ";
    Node* current = head;

    while (current != nullptr) {
        if (current->data.ModeOfTransport == mode) {
            cout << current->data.ResidentID << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void searchLinkedListByDistance(Node* head, double minDistance) {
    cout << "\n[Linked List] Distance > " << minDistance << ": ";
    Node* current = head;

    while (current != nullptr) {
        if (current->data.DailyDistance > minDistance) {
            cout << current->data.ResidentID << " ";
        }
        current = current->next;
    }
    cout << endl;
}
#include "searching.h"
#include <iostream>
#include <chrono>

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

// =====================
// SEARCHING EXPERIMENTS
// =====================

void runArraySearchingExperiment(Resident arr[], int size) {

    string testID = arr[size / 2].ResidentID; // middle element
    int testAge = arr[size / 2].Age;

    auto start = chrono::high_resolution_clock::now();
    linearSearchArrayByID(arr, size, testID);
    auto end = chrono::high_resolution_clock::now();

    cout << "Array Search by ID: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    linearSearchArrayByAge(arr, size, testAge);
    end = chrono::high_resolution_clock::now();

    cout << "Array Search by Age: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;
}

void runLinkedListSearchingExperiment(Node* head) {

    if (!head) return;

    string testID = head->data.ResidentID;
    int testAge = head->data.Age;

    auto start = chrono::high_resolution_clock::now();
    linearSearchListByID(head, testID);
    auto end = chrono::high_resolution_clock::now();

    cout << "Linked List Search by ID: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    linearSearchListByAge(head, testAge);
    auto end2 = chrono::high_resolution_clock::now();

    cout << "Linked List Search by Age: "
         << chrono::duration_cast<chrono::microseconds>(end2 - start).count()
         << " microseconds" << endl;
}
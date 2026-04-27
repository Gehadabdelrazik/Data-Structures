#include "sorting.h"
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

// =====================
// ARRAY SORTING
// =====================

void bubbleSortArrayByID(Resident arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].ResidentID > arr[j + 1].ResidentID) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortArrayByAge(Resident arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].Age > arr[j + 1].Age) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortArrayByCarbon(Resident arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].CarbonEmissionFactor > arr[j + 1].CarbonEmissionFactor) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// =====================
// LINKED LIST SORTING
// =====================

void bubbleSortListByID(Node* head) {
    if (!head) return;

    bool swapped;
    Node* current;

    do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            if (current->data.ResidentID > current->next->data.ResidentID) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }

    } while (swapped);
}

void bubbleSortListByAge(Node* head) {
    if (!head) return;

    bool swapped;
    Node* current;

    do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            if (current->data.Age > current->next->data.Age) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }

    } while (swapped);
}

void bubbleSortListByCarbon(Node* head) {
    if (!head) return;

    bool swapped;
    Node* current;

    do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            if (current->data.CarbonEmissionFactor > current->next->data.CarbonEmissionFactor) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }

    } while (swapped);
}

// =====================
// SORTING EXPERIMENTS
// =====================

void runArraySortingExperiment(Resident arr[], int size) {

    Resident copy1[size];
    Resident copy2[size];
    Resident copy3[size];

    for (int i = 0; i < size; i++) {
        copy1[i] = arr[i];
        copy2[i] = arr[i];
        copy3[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();
    bubbleSortArrayByID(copy1, size);
    auto end = chrono::high_resolution_clock::now();

    cout << "Array Sort by ID: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    bubbleSortArrayByAge(copy2, size);
    end = chrono::high_resolution_clock::now();

    cout << "Array Sort by Age: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    bubbleSortArrayByCarbon(copy3, size);
    end = chrono::high_resolution_clock::now();

    cout << "Array Sort by Carbon: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;
}

void runLinkedListSortingExperiment(Node* head) {

    auto start = chrono::high_resolution_clock::now();
    bubbleSortListByID(head);
    auto end = chrono::high_resolution_clock::now();

    cout << "Linked List Sort by ID: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;
}
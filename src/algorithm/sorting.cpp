#include "sorting.h"
#include <iostream>
#include <chrono>

using namespace std;



void swapResident(Resident &a, Resident &b) {
    Resident temp = a;
    a = b;
    b = temp;
}

double calculateEmission(Resident r) {
    return r.DailyDistance * r.CarbonEmissionFactor * r.AverageDayPerMonth;
}


void bubbleSortArrayByID(Resident arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].ResidentID > arr[j + 1].ResidentID) {
                swapResident(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortArrayByAge(Resident arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].Age > arr[j + 1].Age) {
                swapResident(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortArrayByDistance(Resident arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].DailyDistance > arr[j + 1].DailyDistance) {
                swapResident(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortArrayByCarbon(Resident arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (calculateEmission(arr[j]) > calculateEmission(arr[j + 1])) {
                swapResident(arr[j], arr[j + 1]);
            }
        }
    }
}


void bubbleSortListByID(Node* head) {
    if (!head) return;

    bool swapped;
    Node* current;

    do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            if (current->data.ResidentID > current->next->data.ResidentID) {
                swapResident(current->data, current->next->data);
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
                swapResident(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }

    } while (swapped);
}

void bubbleSortListByDistance(Node* head) {
    if (!head) return;

    bool swapped;
    Node* current;

    do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            if (current->data.DailyDistance > current->next->data.DailyDistance) {
                swapResident(current->data, current->next->data);
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
            if (calculateEmission(current->data) > calculateEmission(current->next->data)) {
                swapResident(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }

    } while (swapped);
}



void runArraySortingExperiment(Resident arr[], int size) {

    Resident copy[size];
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        bubbleSortArrayByAge(copy, size);
    }
    auto end = chrono::high_resolution_clock::now();

    cout << "Array Sort (Age): "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;
}

void runLinkedListSortingExperiment(Node* head) {

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        bubbleSortListByAge(head);
    }
    auto end = chrono::high_resolution_clock::now();

    cout << "Linked List Sort (Age): "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " microseconds" << endl;
}
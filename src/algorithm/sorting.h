#ifndef SORTING_H
#define SORTING_H

#include "../structures/resident.h"
#include "../structures/node.h"

// =====================
// HELPER FUNCTIONS
// =====================
double calculateEmission(Resident r);
void swapResident(Resident &a, Resident &b);

// =====================
// ARRAY SORTING
// =====================
void bubbleSortArrayByID(Resident arr[], int size);
void bubbleSortArrayByAge(Resident arr[], int size);
void bubbleSortArrayByDistance(Resident arr[], int size);
void bubbleSortArrayByCarbon(Resident arr[], int size);

// =====================
// LINKED LIST SORTING
// =====================
void bubbleSortListByID(Node* head);
void bubbleSortListByAge(Node* head);
void bubbleSortListByDistance(Node* head);
void bubbleSortListByCarbon(Node* head);

// =====================
// SORTING EXPERIMENTS
// =====================
void runArraySortingExperiment(Resident arr[], int size);
void runLinkedListSortingExperiment(Node* head);

#endif
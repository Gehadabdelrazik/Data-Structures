#ifndef SORTING_H
#define SORTING_H

#include "../structures/resident.h"
#include "../structures/node.h"

// =====================
// ARRAY SORTING
// =====================
void bubbleSortArrayByID(Resident arr[], int size);
void bubbleSortArrayByAge(Resident arr[], int size);
void bubbleSortArrayByCarbon(Resident arr[], int size);

// =====================
// LINKED LIST SORTING
// =====================
void bubbleSortListByID(Node* head);
void bubbleSortListByAge(Node* head);
void bubbleSortListByCarbon(Node* head);

// =====================
// SORTING EXPERIMENTS
// =====================
void runArraySortingExperiment(Resident arr[], int size);
void runLinkedListSortingExperiment(Node* head);

#endif
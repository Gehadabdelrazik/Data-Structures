#ifndef SORTING_H
#define SORTING_H

#include "../structures/resident.h"
#include "../structures/node.h"


double calculateEmission(Resident r);
void swapResident(Resident &a, Resident &b);


void bubbleSortArrayByID(Resident arr[], int size);
void bubbleSortArrayByAge(Resident arr[], int size);
void bubbleSortArrayByDistance(Resident arr[], int size);
void bubbleSortArrayByCarbon(Resident arr[], int size);


void bubbleSortListByID(Node* head);
void bubbleSortListByAge(Node* head);
void bubbleSortListByDistance(Node* head);
void bubbleSortListByCarbon(Node* head);


void runArraySortingExperiment(Resident arr[], int size);
void runLinkedListSortingExperiment(Node* head);

#endif
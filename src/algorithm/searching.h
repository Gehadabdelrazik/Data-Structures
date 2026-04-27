#ifndef SEARCHING_H
#define SEARCHING_H

#include "../structures/resident.h"
#include "../structures/node.h"

// =====================
// ARRAY SEARCHING
// =====================
int linearSearchArrayByID(Resident arr[], int size, string id);
int linearSearchArrayByAge(Resident arr[], int size, int age);

// =====================
// LINKED LIST SEARCHING
// =====================
Node* linearSearchListByID(Node* head, string id);
Node* linearSearchListByAge(Node* head, int age);

// =====================
// SEARCHING EXPERIMENTS
// =====================
void runArraySearchingExperiment(Resident arr[], int size);
void runLinkedListSearchingExperiment(Node* head);

#endif
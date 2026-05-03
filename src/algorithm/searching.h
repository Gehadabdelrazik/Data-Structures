#ifndef SEARCHING_H
#define SEARCHING_H

#include <string>
#include "../structures/resident.h"
#include "../structures/node.h"

using namespace std;

// =====================
// ARRAY SEARCHING
// =====================
int linearSearchArrayByID(Resident arr[], int size, string id);
int linearSearchArrayByAge(Resident arr[], int size, int age);

// REQUIRED SEARCH FUNCTIONS
void searchArrayByAgeGroup(Resident arr[], int size, int minAge, int maxAge);
void searchArrayByTransport(Resident arr[], int size, string mode);
void searchArrayByDistance(Resident arr[], int size, double minDistance);

// =====================
// LINKED LIST SEARCHING
// =====================
Node* linearSearchListByID(Node* head, string id);
Node* linearSearchListByAge(Node* head, int age);

// REQUIRED SEARCH FUNCTIONS
void searchLinkedListByAgeGroup(Node* head, int minAge, int maxAge);
void searchLinkedListByTransport(Node* head, string mode);
void searchLinkedListByDistance(Node* head, double minDistance);

#endif
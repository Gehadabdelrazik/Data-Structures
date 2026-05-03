#ifndef AGEGROUP_H
#define AGEGROUP_H
 
#include "../structures/resident.h"
#include "../structures/array.h"
#include "../structures/linkedlist.h"
#include <string>
using namespace std;
 
// Returns the age group label string for a given age
string getAgeGroup(int age);
 
// Internal helpers (used by carbon.cpp if needed)
int getAgeGroupIndex(int age);
int getTransportIndex(const string& mode);
 
// Array-based age group analysis
void analyseAgeGroupsArray(ResidentData& data, const string& datasetName);
 
// Linked list-based age group analysis
void analyseAgeGroupsLinkedList(LinkedList& list, const string& datasetName);
 
#endif
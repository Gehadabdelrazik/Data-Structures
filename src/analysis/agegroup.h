#ifndef AGEGROUP_H
#define AGEGROUP_H
 
#include "../structures/resident.h"
#include "../structures/array.h"
#include "../structures/linkedlist.h"
#include <string>
using namespace std;
 
// -------------------------------------------------------
// Age Group Boundaries
// -------------------------------------------------------
// 6  - 17  : Children & Teenagers
// 18 - 25  : University Students / Young Adults
// 26 - 45  : Working Adults (Early Career)
// 46 - 60  : Working Adults (Late Career)
// 61 - 100 : Senior Citizens / Retirees
// -------------------------------------------------------
 
// Returns the age group label for a given age
string getAgeGroup(int age);
 
// -------------------------------------------------------
// ARRAY-BASED Age Group Analysis
// -------------------------------------------------------
 
// Displays a full age group analysis table for an array dataset
// Shows: mode of transport count, total emission, average emission
// per resident, for each age group
void analyseAgeGroupsArray(ResidentData& data, const string& datasetName);
 
// -------------------------------------------------------
// LINKED LIST-BASED Age Group Analysis
// -------------------------------------------------------
 
// Displays a full age group analysis table for a linked list dataset
void analyseAgeGroupsLinkedList(LinkedList& list, const string& datasetName);
 
#endif
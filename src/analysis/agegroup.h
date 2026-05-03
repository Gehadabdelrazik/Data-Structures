#ifndef AGEGROUP_H
#define AGEGROUP_H
 
#include "../structures/resident.h"
#include "../structures/array.h"
#include "../structures/linkedlist.h"
#include <string>
using namespace std;
 

string getAgeGroup(int age);
 

int getAgeGroupIndex(int age);
int getTransportIndex(const string& mode);
 

void analyseAgeGroupsArray(ResidentData& data, const string& datasetName);
 

void analyseAgeGroupsLinkedList(LinkedList& list, const string& datasetName);
 
#endif
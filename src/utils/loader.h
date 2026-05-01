#ifndef LOADER_H
#define LOADER_H
#include "../structures/linkedlist.h"



// Load CSV datasets into ResidentData array

#include "../structures/array.h"
#include <string>
using namespace std;


bool loadDataset(const string& filename, ResidentData& dataset);
bool loadDatasetToList(const string& filename, LinkedList& list);
#endif
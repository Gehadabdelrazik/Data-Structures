#ifndef LOADER_H
#define LOADER_H


// Load CSV datasets into ResidentData array

#include "../structures/array.h"
#include <string>
using namespace std;


bool loadDataset(const string& filename, ResidentData& dataset);

#endif
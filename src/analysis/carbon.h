#ifndef CARBON_H
#define CARBON_H

#include "../structures/resident.h"
#include "../structures/array.h"
#include "../structures/linkedlist.h"
#include <string>
using namespace std;


// 5a. Calculate carbon emission for a single resident
//     Formula: DailyDistance x CarbonEmissionFactor x AverageDayPerMonth
float calculateResidentEmission(const Resident& r);


//array-based implementation
// 5a. Get total emission for an array dataset
float getTotalDatasetEmission(ResidentData& data);

// 5b. Display emissions broken down by mode of transport (array)
void displayEmissionByMode(ResidentData& data, const string& datasetName);

// 5a + 5b. Full analysis table for one array dataset
void displayDatasetAnalysis(ResidentData& data, const string& datasetName);

// 5c + 5d. Cross-dataset comparison table by age group (arrays)
void displayCrossDatasetSummary(ResidentData& dataA,
                                ResidentData& dataB,
                                ResidentData& dataC);

// MASTER: Run all of Task 5 for array-based datasets
void runCarbonAnalysis(ResidentData& dataA,
                       ResidentData& dataB,
                       ResidentData& dataC);


                       
//linked list-based implementation
// 5a. Get total emission for a linked list dataset
float getTotalDatasetEmissionLL(LinkedList& list);

// 5b. Display emissions broken down by mode of transport (linked list)
void displayEmissionByModeLL(LinkedList& list, const string& datasetName);

// 5a + 5b. Full analysis table for one linked list dataset
void displayDatasetAnalysisLL(LinkedList& list, const string& datasetName);

// 5c + 5d. Cross-dataset comparison table by age group (linked lists)
void displayCrossDatasetSummaryLL(LinkedList& listA,
                                  LinkedList& listB,
                                  LinkedList& listC);

// MASTER: Run all of Task 5 for linked list-based datasets
void runCarbonAnalysisLL(LinkedList& listA,
                         LinkedList& listB,
                         LinkedList& listC);

#endif
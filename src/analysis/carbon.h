#ifndef CARBON_H
#define CARBON_H
 
#include "../structures/resident.h"
#include "agegroup.h" 
#include <string>
using namespace std;

//define constants for transport modes and their count for now since we do not do that anywhere else
//suggestion we create constants file



//5a (general formula)
float calculateResidentEmission(const Resident& r);

//5a (total emission for a dataset)
float getTotalDatasetEmission(Resident* residents, int size);


//5b (emission by mode of transport)
void displayEmissionByMode(Resident* residents, int size, string datasetName);


//full table for one dataset
void displayDatasetAnalysis(Resident* residents, int size, string datasetName);

//dataset comparision by age_group
void displayCrossDatasetSummary(Resident* datasetA, int sizeA,
                                 Resident* datasetB, int sizeB,
                                 Resident* datasetC, int sizeC);

                            
//all
void runCarbonAnalysis(Resident* datasetA, int sizeA,
                       Resident* datasetB, int sizeB,
                       Resident* datasetC, int sizeC);
 
#endif
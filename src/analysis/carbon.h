#ifndef CARBON_H
#define CARBON_H

#include "../structures/resident.h"
#include "../structures/array.h"
#include <string>
using namespace std;

float calculateResidentEmission(const Resident& r);

float getTotalDatasetEmission(ResidentData& data);

void displayEmissionByMode(ResidentData& data, const string& datasetName);

void displayDatasetAnalysis(ResidentData& data, const string& datasetName);

void displayCrossDatasetSummary(
    ResidentData& dataA,
    ResidentData& dataB,
    ResidentData& dataC
);

void runCarbonAnalysis(
    ResidentData& dataA,
    ResidentData& dataB,
    ResidentData& dataC
);

#endif
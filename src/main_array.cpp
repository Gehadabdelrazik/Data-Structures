#include "structures/array.h"
#include "utils/loader.h"
#include "algorithm/sorting.h"
#include "algorithm/searching.h"
#include "analysis/carbon.h"
#include "analysis/agegroup.h"

#include <iostream>
using namespace std;

int main() {

    ResidentData cityA(1000);
    ResidentData cityB(1000);
    ResidentData cityC(1000);

    loadDataset("data/dataset1-cityA.csv", cityA);
    loadDataset("data/dataset2-cityB.csv", cityB);
    loadDataset("data/dataset3-cityC.csv", cityC);

    cout << "\n========== ARRAY ANALYSIS ==========\n";

    // Age Group Analysis
    analyseAgeGroupsArray(cityA, "City A");
    analyseAgeGroupsArray(cityB, "City B");
    analyseAgeGroupsArray(cityC, "City C");

    // Carbon Analysis
    runCarbonAnalysis(cityA, cityB, cityC);
 
    // Sorting
    cout << "\n========== ARRAY SORTING ==========\n";
    runArraySortingExperiment(cityA.getData(), cityA.getSize());

    // Searching
    cout << "\n========== ARRAY SEARCHING ==========\n";
    runArraySearchingExperiment(cityA.getData(), cityA.getSize());

    return 0;
}
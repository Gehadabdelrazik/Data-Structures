#include "structures/linkedlist.h"
#include "utils/loader.h"
#include "algorithm/sorting.h"
#include "algorithm/searching.h"
#include "analysis/agegroup.h"

#include <iostream>
using namespace std;

int main() {

    LinkedList cityA;
    LinkedList cityB;

    LinkedList cityC;

    loadDatasetToList("data/dataset1-cityA.csv", cityA);
    loadDatasetToList("data/dataset2-cityB.csv", cityB);
    loadDatasetToList("data/dataset3-cityC.csv", cityC);

    cout << "\n========== LINKED LIST ANALYSIS ==========\n";

    // Age Group Analysis
    analyseAgeGroupsLinkedList(cityA, "City A");
    analyseAgeGroupsLinkedList(cityB, "City B");
    analyseAgeGroupsLinkedList(cityC, "City C");

    // Sorting
    cout << "\n========== SORTING ==========\n";
    runLinkedListSortingExperiment(cityA.getHead());

    // Searching
    cout << "\n========== SEARCHING ==========\n";
    runLinkedListSearchingExperiment(cityA.getHead());

    return 0;
}
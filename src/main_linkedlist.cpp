#include "structures/linkedlist.h"
#include "utils/loader.h"
#include "algorithm/sorting.h"
#include "algorithm/searching.h"
#include "analysis/agegroup.h"

#include <iostream>
#include <locale>
using namespace std;

int main() {

    setlocale(LC_ALL, "");  

    LinkedList cityA;
    LinkedList cityB;
    LinkedList cityC;

    loadDatasetToList("data/dataset1-cityA.csv", cityA);
    loadDatasetToList("data/dataset2-cityB.csv", cityB);
    loadDatasetToList("data/dataset3-cityC.csv", cityC);

    cout << "\n========== LINKED LIST ANALYSIS ==========\n";

    // =====================
    // Age Group Analysis
    // =====================
    analyseAgeGroupsLinkedList(cityA, "City A");
    analyseAgeGroupsLinkedList(cityB, "City B");
    analyseAgeGroupsLinkedList(cityC, "City C");

    
    cout << "\n========== SORTING EXPERIMENT ==========\n";

    cout << "\n--- City A ---\n";
    runLinkedListSortingExperiment(cityA.getHead());

    cout << "\n--- City B ---\n";
    runLinkedListSortingExperiment(cityB.getHead());

    cout << "\n--- City C ---\n";
    runLinkedListSortingExperiment(cityC.getHead());

   
    cout << "\n========== SEARCHING EXPERIMENT ==========\n";

    cout << "\n--- City A ---\n";
    searchLinkedListByAgeGroup(cityA.getHead(), 26, 45);
    searchLinkedListByTransport(cityA.getHead(), "Car");
    searchLinkedListByDistance(cityA.getHead(), 15);

    cout << "\n--- City B ---\n";
    searchLinkedListByAgeGroup(cityB.getHead(), 26, 45);
    searchLinkedListByTransport(cityB.getHead(), "Car");
    searchLinkedListByDistance(cityB.getHead(), 15);

    cout << "\n--- City C ---\n";
    searchLinkedListByAgeGroup(cityC.getHead(), 26, 45);
    searchLinkedListByTransport(cityC.getHead(), "Car");
    searchLinkedListByDistance(cityC.getHead(), 15);

    return 0;
}
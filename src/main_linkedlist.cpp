#include "structures/linkedlist.h"
#include "utils/loader.h"
#include "algorithm/sorting.h"
#include "algorithm/searching.h"
#include "analysis/agegroup.h"
#include "analysis/carbon.h"

#include <iostream>
#include <locale>
#include <string>
#include <chrono>

using namespace std;

void runLinkedListSortingMenu(LinkedList& cityA, LinkedList& cityB, LinkedList& cityC) {
    int datasetChoice, sortChoice;

    cout << "\nChoose dataset to sort:\n";
    cout << "1. City A\n";
    cout << "2. City B\n";
    cout << "3. City C\n";
    cout << "Enter choice: ";
    cin >> datasetChoice;

    LinkedList* selected = nullptr;
    string name;

    if (datasetChoice == 1) {
        selected = &cityA;
        name = "City A";
    } else if (datasetChoice == 2) {
        selected = &cityB;
        name = "City B";
    } else if (datasetChoice == 3) {
        selected = &cityC;
        name = "City C";
    } else {
        cout << "Invalid dataset choice.\n";
        return;
    }

    cout << "\nSort by:\n";
    cout << "1. Resident ID\n";
    cout << "2. Age\n";
    cout << "3. Daily Distance\n";
    cout << "4. Carbon Emission\n";
    cout << "Enter choice: ";
    cin >> sortChoice;

    auto start = chrono::high_resolution_clock::now();

    if (sortChoice == 1) {
        bubbleSortListByID(selected->getHead());
    } else if (sortChoice == 2) {
        bubbleSortListByAge(selected->getHead());
    } else if (sortChoice == 3) {
        bubbleSortListByDistance(selected->getHead());
    } else if (sortChoice == 4) {
        bubbleSortListByCarbon(selected->getHead());
    } else {
        cout << "Invalid sorting choice.\n";
        return;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nSorted " << name << " successfully.\n";
    cout << "Execution Time: " << duration.count() << " microseconds\n";

    selected->displayAll();
}

void runLinkedListSearchingMenu(LinkedList& cityA, LinkedList& cityB, LinkedList& cityC) {
    int datasetChoice, searchChoice;

    cout << "\nChoose dataset to search:\n";
    cout << "1. City A\n";
    cout << "2. City B\n";
    cout << "3. City C\n";
    cout << "Enter choice: ";
    cin >> datasetChoice;

    LinkedList* selected = nullptr;

    if (datasetChoice == 1) {
        selected = &cityA;
    } else if (datasetChoice == 2) {
        selected = &cityB;
    } else if (datasetChoice == 3) {
        selected = &cityC;
    } else {
        cout << "Invalid dataset choice.\n";
        return;
    }

    cout << "\nSearch by:\n";
    cout << "1. Age Group\n";
    cout << "2. Mode of Transport\n";
    cout << "3. Daily Distance Threshold\n";
    cout << "Enter choice: ";
    cin >> searchChoice;

    auto start = chrono::high_resolution_clock::now();

    if (searchChoice == 1) {
        int minAge, maxAge;

        cout << "Enter minimum age: ";
        cin >> minAge;

        cout << "Enter maximum age: ";
        cin >> maxAge;

        searchLinkedListByAgeGroup(selected->getHead(), minAge, maxAge);
    } 
    else if (searchChoice == 2) {
        string mode;

        cout << "Enter transport mode, example Car, Bus, Bicycle, Walking: ";
        cin.ignore();
        getline(cin, mode);

        searchLinkedListByTransport(selected->getHead(), mode);
    } 
    else if (searchChoice == 3) {
        double distance;

        cout << "Enter minimum daily distance: ";
        cin >> distance;

        searchLinkedListByDistance(selected->getHead(), distance);
    } 
    else {
        cout << "Invalid searching choice.\n";
        return;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nExecution Time: " << duration.count() << " microseconds\n";
}

int main() {
    setlocale(LC_ALL, "");

    LinkedList cityA;
    LinkedList cityB;
    LinkedList cityC;

    loadDatasetToList("data/dataset1-cityA.csv", cityA);
    loadDatasetToList("data/dataset2-cityB.csv", cityB);
    loadDatasetToList("data/dataset3-cityC.csv", cityC);

    int choice;

    do {
        cout << "\n========== LINKED LIST SYSTEM ==========\n";
        cout << "1. Display Dataset 1 - City A\n";
        cout << "2. Display Dataset 2 - City B\n";
        cout << "3. Display Dataset 3 - City C\n";
        cout << "4. Age Group Analysis\n";
        cout << "5. Carbon Emission Analysis\n";
        cout << "6. Sorting Experiment\n";
        cout << "7. Searching Experiment\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n===== Dataset 1 - City A =====\n";
            cityA.displayAll();
            break;

        case 2:
            cout << "\n===== Dataset 2 - City B =====\n";
            cityB.displayAll();
            break;

        case 3:
            cout << "\n===== Dataset 3 - City C =====\n";
            cityC.displayAll();
            break;

        case 4:
            analyseAgeGroupsLinkedList(cityA, "City A");
            analyseAgeGroupsLinkedList(cityB, "City B");
            analyseAgeGroupsLinkedList(cityC, "City C");
            break;

        case 5:
            runCarbonAnalysisLL(cityA, cityB, cityC);
            break;

        case 6:
            runLinkedListSortingMenu(cityA, cityB, cityC);
            break;

        case 7:
            runLinkedListSearchingMenu(cityA, cityB, cityC);
            break;

        case 0:
            cout << "Exiting Linked List System...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
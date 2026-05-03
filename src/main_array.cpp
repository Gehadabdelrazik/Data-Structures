#include "structures/array.h"
#include "utils/loader.h"
#include "algorithm/sorting.h"
#include "algorithm/searching.h"
#include "analysis/carbon.h"
#include "analysis/agegroup.h"

#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <chrono>

using namespace std;

void displayArray(ResidentData& data, string name) {
    cout << "\n===== " << name << " =====\n";

    cout << left
         << setw(15) << "Resident ID"
         << setw(8)  << "Age"
         << setw(18) << "Transport"
         << setw(15) << "Distance"
         << setw(15) << "Factor"
         << setw(15) << "Days/Month" << endl;

    cout << string(86, '-') << endl;

    for (int i = 0; i < data.getSize(); i++) {
        Resident r = data.get(i);

        cout << left
             << setw(15) << r.ResidentID
             << setw(8)  << r.Age
             << setw(18) << r.ModeOfTransport
             << setw(15) << r.DailyDistance
             << setw(15) << r.CarbonEmissionFactor
             << setw(15) << r.AverageDayPerMonth
             << endl;
    }
}

void runArraySortingMenu(ResidentData& cityA, ResidentData& cityB, ResidentData& cityC) {
    int datasetChoice, sortChoice;

    cout << "\nChoose dataset to sort:\n";
    cout << "1. City A\n";
    cout << "2. City B\n";
    cout << "3. City C\n";
    cout << "Enter choice: ";
    cin >> datasetChoice;

    ResidentData* selected = nullptr;
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
        bubbleSortArrayByID(selected->getData(), selected->getSize());
    } else if (sortChoice == 2) {
        bubbleSortArrayByAge(selected->getData(), selected->getSize());
    } else if (sortChoice == 3) {
        bubbleSortArrayByDistance(selected->getData(), selected->getSize());
    } else if (sortChoice == 4) {
        bubbleSortArrayByCarbon(selected->getData(), selected->getSize());
    } else {
        cout << "Invalid sorting choice.\n";
        return;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "\nSorted " << name << " successfully.\n";
    cout << "Execution Time: " << duration.count() << " microseconds\n";

    displayArray(*selected, name);
}

void runArraySearchingMenu(ResidentData& cityA, ResidentData& cityB, ResidentData& cityC) {
    int datasetChoice, searchChoice;

    cout << "\nChoose dataset to search:\n";
    cout << "1. City A\n";
    cout << "2. City B\n";
    cout << "3. City C\n";
    cout << "Enter choice: ";
    cin >> datasetChoice;

    ResidentData* selected = nullptr;

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

        searchArrayByAgeGroup(selected->getData(), selected->getSize(), minAge, maxAge);
    } 
    else if (searchChoice == 2) {
        string mode;

        cout << "Enter transport mode, example Car, Bus, Bicycle, Walking: ";
        cin.ignore();
        getline(cin, mode);

        searchArrayByTransport(selected->getData(), selected->getSize(), mode);
    } 
    else if (searchChoice == 3) {
        double distance;

        cout << "Enter minimum daily distance: ";
        cin >> distance;

        searchArrayByDistance(selected->getData(), selected->getSize(), distance);
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

    ResidentData cityA(1000);
    ResidentData cityB(1000);
    ResidentData cityC(1000);

    loadDataset("data/dataset1-cityA.csv", cityA);
    loadDataset("data/dataset2-cityB.csv", cityB);
    loadDataset("data/dataset3-cityC.csv", cityC);

    int choice;

    do {
        cout << "\n========== ARRAY SYSTEM ==========\n";
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
            displayArray(cityA, "Dataset 1 - City A");
            break;

        case 2:
            displayArray(cityB, "Dataset 2 - City B");
            break;

        case 3:
            displayArray(cityC, "Dataset 3 - City C");
            break;

        case 4:
            analyseAgeGroupsArray(cityA, "City A");
            analyseAgeGroupsArray(cityB, "City B");
            analyseAgeGroupsArray(cityC, "City C");
            break;

        case 5:
            runCarbonAnalysis(cityA, cityB, cityC);
            break;

        case 6:
            runArraySortingMenu(cityA, cityB, cityC);
            break;

        case 7:
            runArraySearchingMenu(cityA, cityB, cityC);
            break;

        case 0:
            cout << "Exiting Array System...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
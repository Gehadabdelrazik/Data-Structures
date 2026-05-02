#include "structures/array.h"
#include "utils/loader.h"
#include "algorithm/sorting.h"
#include "algorithm/searching.h"
#include "analysis/carbon.h"
#include "analysis/agegroup.h"

#include <iostream>
#include <iomanip>
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

int main() {
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
            cout << "\n========== ARRAY SORTING ==========\n";
            runArraySortingExperiment(cityA.getData(), cityA.getSize());
            break;

        case 7:
            cout << "\n========== ARRAY SEARCHING ==========\n";
            runArraySearchingExperiment(cityA.getData(), cityA.getSize());
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
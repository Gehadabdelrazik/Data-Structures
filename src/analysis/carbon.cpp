#include "carbon.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


//constants
const int    C_NUM_TRANSPORT_MODES = 6;
const string C_TRANSPORT_MODES[6]  = {
    "Car", "Bus", "Bicycle", "Walking", "School Bus", "Carpool"
};
 
const int    C_NUM_AGE_GROUPS    = 5;
const string C_AGE_GROUP_LABELS[5] = {
    "6-17   (Children & Teenagers)",
    "18-25  (University Students / Young Adults)",
    "26-45  (Working Adults - Early Career)",
    "46-60  (Working Adults - Late Career)",
    "61-100 (Senior Citizens / Retirees)"
};
 
const int C_AGE_MIN[5] = {  6, 18, 26, 46,  61 };
const int C_AGE_MAX[5] = { 17, 25, 45, 60, 100 };


int getCarbonAgeGroupIndex(int age) {
    if (age >= 6  && age <= 17)  return 0;
    if (age >= 18 && age <= 25)  return 1;
    if (age >= 26 && age <= 45)  return 2;
    if (age >= 46 && age <= 60)  return 3;
    if (age >= 61 && age <= 100) return 4;
    return -1;
}
 
// Prints a horizontal separator line of the given width.
void printLine(int width) {
    cout << string(width, '-') << endl;
}


// 5a- single resident emission calculation
float calculateResidentEmission(const Resident& r) {
    return r.DailyDistance * r.CarbonEmissionFactor * r.AverageDayPerMonth;
}

//array-based implementation
//5a- sum resident for every resident in array dataset
float getTotalDatasetEmission(ResidentData& data) {
    float total = 0;
    for (int i = 0; i < data.getSize(); i++)
        total += calculateResidentEmission(data.get(i));
    return total;
}


// 5b- print a breakdown of total emissions per mode of transport (array)
void displayEmissionByMode(ResidentData& data, const string& datasetName) {
 
    cout << "\nDataset: " << datasetName << endl;
    printLine(60);
    cout << left
         << setw(24) << "Mode of Transport"
         << setw(10) << "Count"
         << "Total Emission (kg CO2)" << endl;
    printLine(60);
 
    float datasetTotal = 0;
 
    // iterate each transport mode and accumulate matching residents
    for (int m = 0; m < C_NUM_TRANSPORT_MODES; m++) {
 
        int   count         = 0;
        float totalEmission = 0;
 
        for (int i = 0; i < data.getSize(); i++) {
            Resident r = data.get(i);
            if (r.ModeOfTransport == C_TRANSPORT_MODES[m]) {
                count++;
                totalEmission += calculateResidentEmission(r);
            }
        }
 
        // only print transport modes that appear in this dataset
        if (count > 0) {
            cout << left
                 << setw(24) << C_TRANSPORT_MODES[m]
                 << setw(10) << count
                 << fixed << setprecision(2) << totalEmission << endl;
            datasetTotal += totalEmission;
        }
    }
 
    printLine(60);
    cout << "Dataset Total: "
         << fixed << setprecision(2) << datasetTotal << " kg CO2" << endl;
}


// 5a + 5b- full analysis table for one dataset
void displayDatasetAnalysis(ResidentData& data, const string& datasetName) {
 
    cout << "\n-----------------------------------------------------------" << endl;
    cout << " CARBON EMISSION ANALYSIS — " << datasetName                    << endl;
    cout << "-----------------------------------------------------------"   << endl;
 
    // 5b — breakdown by mode of transport
    displayEmissionByMode(data, datasetName);
 
    // 5a — grand total for this dataset
    cout << "\nTotal Carbon Emission for " << datasetName << ": "
         << fixed << setprecision(2)
         << getTotalDatasetEmission(data) << " kg CO2" << endl;
}


// 5c + 5d- cross-dataset comparison table broken down by age group (arrays).
void displayCrossDatasetSummary(ResidentData& dataA,
                                ResidentData& dataB,
                                ResidentData& dataC) {
 
    cout << "\n-----------------------------------------------------------" << endl;
    cout << " CROSS-DATASET COMPARISON — Emissions by Age Group (Arrays)"         << endl;
    cout << "-----------------------------------------------------------"   << endl;
    cout << left
         << setw(46) << "Age Group"
         << setw(16) << "City A (kg CO2)"
         << setw(16) << "City B (kg CO2)"
         <<             "City C (kg CO2)" << endl;
    printLine(94);
 
    float grandA = 0, grandB = 0, grandC = 0;
 
    for (int g = 0; g < C_NUM_AGE_GROUPS; g++) {
 
        float emA = 0, emB = 0, emC = 0;
 
        for (int i = 0; i < dataA.getSize(); i++) {
            Resident r = dataA.get(i);
            if (getCarbonAgeGroupIndex(r.Age) == g)
                emA += calculateResidentEmission(r);
        }
 
        for (int i = 0; i < dataB.getSize(); i++) {
            Resident r = dataB.get(i);
            if (getCarbonAgeGroupIndex(r.Age) == g)
                emB += calculateResidentEmission(r);
        }
 
        for (int i = 0; i < dataC.getSize(); i++) {
            Resident r = dataC.get(i);
            if (getCarbonAgeGroupIndex(r.Age) == g)
                emC += calculateResidentEmission(r);
        }
 
        cout << left
             << setw(46) << C_AGE_GROUP_LABELS[g]
             << setw(16) << fixed << setprecision(2) << emA
             << setw(16) << fixed << setprecision(2) << emB
             <<             fixed << setprecision(2) << emC << endl;
 
        grandA += emA;
        grandB += emB;
        grandC += emC;
    }
 
    printLine(94);
 
    // Grand total row
    cout << left
         << setw(46) << "GRAND TOTAL"
         << setw(16) << fixed << setprecision(2) << grandA
         << setw(16) << fixed << setprecision(2) << grandB
         <<             fixed << setprecision(2) << grandC << endl;
    cout << string(94, '=') << endl;
}





void runCarbonAnalysis(ResidentData& dataA,
                       ResidentData& dataB,
                       ResidentData& dataC) {
 
    displayDatasetAnalysis(dataA, "Dataset 1 - City A (Metropolitan City)");
    displayDatasetAnalysis(dataB, "Dataset 2 - City B (University Town)");
    displayDatasetAnalysis(dataC, "Dataset 3 - City C (Suburban/Rural Area)");
 
    displayCrossDatasetSummary(dataA, dataB, dataC);
}







float getTotalDatasetEmissionLL(LinkedList& list) {
    float total   = 0;
    Node* current = list.getHead();
 
    while (current != nullptr) {
        total  += calculateResidentEmission(current->data);
        current = current->next;
    }
    return total;
}



// 5b- print a breakdown of total emissions per mode of transport (linked list)
void displayEmissionByModeLL(LinkedList& list, const string& datasetName) {
 
    cout << "\nDataset: " << datasetName << endl;
    printLine(60);
    cout << left
         << setw(24) << "Mode of Transport"
         << setw(10) << "Count"
         << "Total Emission (kg CO2)" << endl;
    printLine(60);
 
    float datasetTotal = 0;
 
    // iterate each transport mode and traverse the list for matches
    for (int m = 0; m < C_NUM_TRANSPORT_MODES; m++) {
 
        int   count         = 0;
        float totalEmission = 0;
 
        Node* current = list.getHead();
        while (current != nullptr) {
            if (current->data.ModeOfTransport == C_TRANSPORT_MODES[m]) {
                count++;
                totalEmission += calculateResidentEmission(current->data);
            }
            current = current->next;
        }
 
        
        if (count > 0) {
            cout << left
                 << setw(24) << C_TRANSPORT_MODES[m]
                 << setw(10) << count
                 << fixed << setprecision(2) << totalEmission << endl;
            datasetTotal += totalEmission;
        }
    }
 
    printLine(60);
    cout << "Dataset Total: "
         << fixed << setprecision(2) << datasetTotal << " kg CO2" << endl;
}
 



// 5a + 5b- full carbon analysis table for one linked list dataset
void displayDatasetAnalysisLL(LinkedList& list, const string& datasetName) {
 
    cout << "\n-------------------------------------------------------------" << endl;
    cout << " CARBON EMISSION ANALYSIS — " << datasetName                    << endl;
    cout << "-------------------------------------------------------------"   << endl;
 
    // 5b — breakdown by mode of transport
    displayEmissionByModeLL(list, datasetName);
 
    // 5a — grand total for this dataset
    cout << "\nTotal Carbon Emission for " << datasetName << ": "
         << fixed << setprecision(2)
         << getTotalDatasetEmissionLL(list) << " kg CO2" << endl;
}
 
 
// 5c + 5d- cross-dataset comparison table broken down by age group (linked lists)
void displayCrossDatasetSummaryLL(LinkedList& listA,
                                  LinkedList& listB,
                                  LinkedList& listC) {
 
    cout << "\n-------------------------------------------------------------" << endl;
    cout << " CROSS-DATASET COMPARISON — Emissions by Age Group (Linked Lists)"   << endl;
    cout << "-------------------------------------------------------------"   << endl;
    cout << left
         << setw(46) << "Age Group"
         << setw(16) << "City A (kg CO2)"
         << setw(16) << "City B (kg CO2)"
         <<             "City C (kg CO2)" << endl;
    printLine(94);
 
    float grandA = 0, grandB = 0, grandC = 0;
 
    for (int g = 0; g < C_NUM_AGE_GROUPS; g++) {
 
        float emA = 0, emB = 0, emC = 0;
 
        // Traverse list A
        Node* cur = listA.getHead();
        while (cur != nullptr) {
            if (getCarbonAgeGroupIndex(cur->data.Age) == g)
                emA += calculateResidentEmission(cur->data);
            cur = cur->next;
        }
 
        // Traverse list B
        cur = listB.getHead();
        while (cur != nullptr) {
            if (getCarbonAgeGroupIndex(cur->data.Age) == g)
                emB += calculateResidentEmission(cur->data);
            cur = cur->next;
        }
 
        // Traverse list C
        cur = listC.getHead();
        while (cur != nullptr) {
            if (getCarbonAgeGroupIndex(cur->data.Age) == g)
                emC += calculateResidentEmission(cur->data);
            cur = cur->next;
        }
 
        cout << left
             << setw(46) << C_AGE_GROUP_LABELS[g]
             << setw(16) << fixed << setprecision(2) << emA
             << setw(16) << fixed << setprecision(2) << emB
             <<             fixed << setprecision(2) << emC << endl;
 
        grandA += emA;
        grandB += emB;
        grandC += emC;
    }
 
    printLine(94);
 
    // grand total row
    cout << left
         << setw(46) << "GRAND TOTAL"
         << setw(16) << fixed << setprecision(2) << grandA
         << setw(16) << fixed << setprecision(2) << grandB
         <<             fixed << setprecision(2) << grandC << endl;
    cout << string(94, '=') << endl;
}
 
 

void runCarbonAnalysisLL(LinkedList& listA,
                         LinkedList& listB,
                         LinkedList& listC) {
 
    displayDatasetAnalysisLL(listA, "Dataset 1 - City A (Metropolitan City)");
    displayDatasetAnalysisLL(listB, "Dataset 2 - City B (University Town)");
    displayDatasetAnalysisLL(listC, "Dataset 3 - City C (Suburban/Rural Area)");
 
    displayCrossDatasetSummaryLL(listA, listB, listC);
}
#include "agegroup.h"
#include "../structures/resident.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
// -------------------------------------------------------
// CONSTANTS
// -------------------------------------------------------
 
// Total number of age groups defined in the assignment
const int NUM_AGE_GROUPS = 5;
 
// Age group labels
const string AGE_GROUP_LABELS[NUM_AGE_GROUPS] = {
    "6-17   (Children & Teenagers)",
    "18-25  (University Students / Young Adults)",
    "26-45  (Working Adults - Early Career)",
    "46-60  (Working Adults - Late Career)",
    "61-100 (Senior Citizens / Retirees)"
};
 
// Transport modes present across all datasets
const int NUM_TRANSPORT_MODES = 6;
const string TRANSPORT_MODES[NUM_TRANSPORT_MODES] = {
    "Car", "Bus", "Bicycle", "Walking", "School Bus", "Carpool"
};
 
// -------------------------------------------------------
// HELPER: getAgeGroup
// Returns the index (0-4) of the age group for a given age
// Returns -1 if age is out of defined range
// -------------------------------------------------------
int getAgeGroupIndex(int age) {
    if (age >= 6  && age <= 17)  return 0;
    if (age >= 18 && age <= 25)  return 1;
    if (age >= 26 && age <= 45)  return 2;
    if (age >= 46 && age <= 60)  return 3;
    if (age >= 61 && age <= 100) return 4;
    return -1; // age out of range
}
 
// -------------------------------------------------------
// HELPER: getAgeGroup (public - returns string label)
// -------------------------------------------------------
string getAgeGroup(int age) {
    int idx = getAgeGroupIndex(age);
    if (idx == -1) return "Unknown";
    return AGE_GROUP_LABELS[idx];
}
 
// -------------------------------------------------------
// HELPER: getTransportIndex
// Returns the index of a transport mode string
// Returns -1 if not found
// -------------------------------------------------------
int getTransportIndex(const string& mode) {
    for (int i = 0; i < NUM_TRANSPORT_MODES; i++) {
        if (TRANSPORT_MODES[i] == mode) return i;
    }
    return -1;
}
 
// -------------------------------------------------------
// HELPER: printAgeGroupTable
// Shared display logic used by both array and linked list
// versions. Receives pre-computed arrays of data.
//
// Parameters:
//   transportCount[group][transport] - count of each transport per group
//   totalEmission[group]             - total CO2 per group
//   residentCount[group]             - number of residents per group
//   datasetName                      - label for the header
// -------------------------------------------------------
void printAgeGroupTable(
    int    transportCount[NUM_AGE_GROUPS][6],
    double totalEmission[NUM_AGE_GROUPS],
    int    residentCount[NUM_AGE_GROUPS],
    const string& datasetName)
{
    cout << "\n";
    cout << "========================================================" << endl;
    cout << "  AGE GROUP ANALYSIS — " << datasetName                   << endl;
    cout << "========================================================" << endl;
 
    for (int g = 0; g < NUM_AGE_GROUPS; g++) {
 
        // Skip age groups with no residents in this dataset
        if (residentCount[g] == 0) continue;
 
        cout << "\nAge Group: " << AGE_GROUP_LABELS[g] << endl;
        cout << string(60, '-') << endl;
 
        // Header row
        cout << left
             << setw(14) << "Transport"
             << setw(8)  << "Count"
             << setw(24) << "Total Emission (kg CO2)"
             << setw(22) << "Avg per Resident"
             << endl;
        cout << string(60, '-') << endl;
 
        // Find the most preferred transport (highest count) for this group
        int maxCount   = 0;
        int maxTransport = 0;
        for (int t = 0; t < NUM_TRANSPORT_MODES; t++) {
            if (transportCount[g][t] > maxCount) {
                maxCount     = transportCount[g][t];
                maxTransport = t;
            }
        }
 
        // Print each transport mode that has at least 1 resident
        for (int t = 0; t < NUM_TRANSPORT_MODES; t++) {
            if (transportCount[g][t] == 0) continue;
 
            // Calculate emission for this transport within this group
            // (we re-derive per-transport emission below, so we store it separately)
            // Here we just show the row — per-transport emission is accumulated
            // in the analyseAgeGroups functions below.
            cout << left
                 << setw(14) << TRANSPORT_MODES[t]
                 << setw(8)  << transportCount[g][t];
 
            // Placeholder: per-transport emission shown in carbon.cpp
            // Here we mark the most preferred with an asterisk
            if (t == maxTransport)
                cout << setw(24) << "  (Most Preferred **)";
            else
                cout << setw(24) << "";
 
            cout << endl;
        }
 
        cout << string(60, '-') << endl;
 
        // Summary line for this age group
        double avgEmission = (residentCount[g] > 0)
                             ? totalEmission[g] / residentCount[g]
                             : 0.0;
 
        cout << fixed << setprecision(2);
        cout << "  Total Residents    : " << residentCount[g]      << endl;
        cout << "  Most Preferred     : " << TRANSPORT_MODES[maxTransport] << endl;
        cout << "  Total Emission     : " << totalEmission[g]      << " kg CO2" << endl;
        cout << "  Avg Emission/Res.  : " << avgEmission           << " kg CO2" << endl;
        cout << string(60, '-') << endl;
    }
 
    cout << "========================================================\n" << endl;
}
 
// -------------------------------------------------------
// ARRAY-BASED Analysis
// Iterates through ResidentData array, buckets each resident
// into their age group, accumulates transport counts and
// carbon emissions, then prints the result table.
//
// Carbon emission per resident =
//   DailyDistance * CarbonEmissionFactor * AverageDayPerMonth
// -------------------------------------------------------
void analyseAgeGroupsArray(ResidentData& data, const string& datasetName) {
 
    // 2D array: transportCount[ageGroup][transportMode]
    int    transportCount[NUM_AGE_GROUPS][NUM_TRANSPORT_MODES] = {};
    double totalEmission [NUM_AGE_GROUPS]                      = {};
    int    residentCount [NUM_AGE_GROUPS]                      = {};
 
    int n = data.getSize();
 
    for (int i = 0; i < n; i++) {
        Resident r = data.get(i);
 
        int g = getAgeGroupIndex(r.Age);
        if (g == -1) continue; // skip residents outside defined age range
 
        int t = getTransportIndex(r.ModeOfTransport);
        if (t == -1) t = 0;   // fallback — should not happen with clean data
 
        // Monthly carbon emission for this resident
        float emission = r.DailyDistance * r.CarbonEmissionFactor * r.AverageDayPerMonth;
 
        transportCount[g][t]++;
        totalEmission [g] += emission;
        residentCount [g]++;
    }
 
    printAgeGroupTable(transportCount, totalEmission, residentCount, datasetName);
}
 
// -------------------------------------------------------
// LINKED LIST-BASED Analysis
// Traverses the linked list from head to tail, applying the
// same bucketing logic as the array version above.
// -------------------------------------------------------
void analyseAgeGroupsLinkedList(LinkedList& list, const string& datasetName) {
 
    int    transportCount[NUM_AGE_GROUPS][NUM_TRANSPORT_MODES] = {};
    double totalEmission [NUM_AGE_GROUPS]                      = {};
    int    residentCount [NUM_AGE_GROUPS]                      = {};
 
    // Traverse linked list using the head pointer
    Node* current = list.getHead();
 
    while (current != nullptr) {
        Resident r = current->data;
 
        int g = getAgeGroupIndex(r.Age);
        if (g == -1) {
            current = current->next;
            continue;
        }
 
        int t = getTransportIndex(r.ModeOfTransport);
        if (t == -1) t = 0;
 
        float emission = r.DailyDistance * r.CarbonEmissionFactor * r.AverageDayPerMonth;
 
        transportCount[g][t]++;
        totalEmission [g] += emission;
        residentCount [g]++;
 
        current = current->next;
    }
 
    printAgeGroupTable(transportCount, totalEmission, residentCount, datasetName);
}
 
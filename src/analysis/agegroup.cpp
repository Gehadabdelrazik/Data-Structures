#include "agegroup.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
// -------------------------------------------------------
// CONSTANTS
// -------------------------------------------------------
 
const int NUM_AGE_GROUPS = 5;
 
const string AGE_GROUP_LABELS[NUM_AGE_GROUPS] = {
    "6-17   (Children & Teenagers)",
    "18-25  (University Students / Young Adults)",
    "26-45  (Working Adults - Early Career)",
    "46-60  (Working Adults - Late Career)",
    "61-100 (Senior Citizens / Retirees)"
};
 
const int NUM_TRANSPORT_MODES = 6;
 
const string TRANSPORT_MODES[NUM_TRANSPORT_MODES] = {
    "Car", "Bus", "Bicycle", "Walking", "School Bus", "Carpool"
};
 
// -------------------------------------------------------
// HELPER: getAgeGroupIndex
// Returns 0-4 for valid ages, -1 for out of range
// -------------------------------------------------------
int getAgeGroupIndex(int age) {
    if (age >= 6  && age <= 17)  return 0;
    if (age >= 18 && age <= 25)  return 1;
    if (age >= 26 && age <= 45)  return 2;
    if (age >= 46 && age <= 60)  return 3;
    if (age >= 61 && age <= 100) return 4;
    return -1;
}
 
// -------------------------------------------------------
// HELPER: getAgeGroup
// Public function - returns the string label for an age
// -------------------------------------------------------
string getAgeGroup(int age) {
    int idx = getAgeGroupIndex(age);
    if (idx == -1) return "Unknown";
    return AGE_GROUP_LABELS[idx];
}
 
// -------------------------------------------------------
// HELPER: getTransportIndex
// Returns 0-5 for known transport modes, -1 if not found
// -------------------------------------------------------
int getTransportIndex(const string& mode) {
    for (int i = 0; i < NUM_TRANSPORT_MODES; i++) {
        if (TRANSPORT_MODES[i] == mode) return i;
    }
    return -1;
}
 
// -------------------------------------------------------
// HELPER: printAgeGroupTable
//
// Prints the full age group analysis table.
// Shows emission per transport per age group as required.
//
// transportCount[group][transport]    - resident count
// transportEmission[group][transport] - total CO2 per transport
// totalEmission[group]                - total CO2 for whole group
// residentCount[group]                - total residents in group
// -------------------------------------------------------
void printAgeGroupTable(
    int    transportCount   [NUM_AGE_GROUPS][6],
    double transportEmission[NUM_AGE_GROUPS][6],
    double totalEmission    [NUM_AGE_GROUPS],
    int    residentCount    [NUM_AGE_GROUPS],
    const string& datasetName)
{
    cout << "\n";
    cout << "========================================================" << endl;
    cout << "  AGE GROUP ANALYSIS - " << datasetName                   << endl;
    cout << "========================================================" << endl;
 
    for (int g = 0; g < NUM_AGE_GROUPS; g++) {
 
        if (residentCount[g] == 0) continue;
 
        cout << "\nAge Group: " << AGE_GROUP_LABELS[g] << endl;
        cout << string(68, '-') << endl;
 
        cout << left
             << setw(14) << "Transport"
             << setw(10) << "Count"
             << setw(26) << "Total Emission (kg CO2)"
             << setw(22) << "Avg per Resident"
             << endl;
        cout << string(68, '-') << endl;
 
        // Find most preferred transport (highest resident count)
        int maxCount     = 0;
        int maxTransport = 0;
        for (int t = 0; t < NUM_TRANSPORT_MODES; t++) {
            if (transportCount[g][t] > maxCount) {
                maxCount     = transportCount[g][t];
                maxTransport = t;
            }
        }
 
        // Print one row per transport mode that exists in this group
        for (int t = 0; t < NUM_TRANSPORT_MODES; t++) {
            if (transportCount[g][t] == 0) continue;
 
            double avgPerResident = transportEmission[g][t] / transportCount[g][t];
 
            cout << fixed << setprecision(2);
            cout << left
                 << setw(14) << TRANSPORT_MODES[t]
                 << setw(10) << transportCount[g][t]
                 << setw(26) << transportEmission[g][t]
                 << setw(22) << avgPerResident;
 
            if (t == maxTransport)
                cout << "<-- Most Preferred";
 
            cout << endl;
        }
 
        cout << string(68, '-') << endl;
 
        double avgGroupEmission = totalEmission[g] / residentCount[g];
 
        cout << fixed << setprecision(2);
        cout << "  Total Residents    : " << residentCount[g]            << endl;
        cout << "  Most Preferred     : " << TRANSPORT_MODES[maxTransport] << endl;
        cout << "  Total Emission     : " << totalEmission[g]            << " kg CO2" << endl;
        cout << "  Avg Emission/Res.  : " << avgGroupEmission             << " kg CO2" << endl;
        cout << string(68, '-') << endl;
    }
 
    cout << "========================================================\n" << endl;
}
 
// -------------------------------------------------------
// ARRAY-BASED Age Group Analysis
// -------------------------------------------------------
void analyseAgeGroupsArray(ResidentData& data, const string& datasetName) {
 
    int    transportCount   [NUM_AGE_GROUPS][NUM_TRANSPORT_MODES] = {};
    double transportEmission[NUM_AGE_GROUPS][NUM_TRANSPORT_MODES] = {};
    double totalEmission    [NUM_AGE_GROUPS]                      = {};
    int    residentCount    [NUM_AGE_GROUPS]                      = {};
 
    int n = data.getSize();
 
    for (int i = 0; i < n; i++) {
        Resident r = data.get(i);
 
        int g = getAgeGroupIndex(r.Age);
        if (g == -1) continue;
 
        int t = getTransportIndex(r.ModeOfTransport);
        if (t == -1) continue;
 
        // Monthly carbon emission: distance x factor x days
        double emission = r.DailyDistance * r.CarbonEmissionFactor * r.AverageDayPerMonth;
 
        transportCount   [g][t]++;
        transportEmission[g][t] += emission;
        totalEmission    [g]    += emission;
        residentCount    [g]++;
    }
 
    printAgeGroupTable(transportCount, transportEmission, totalEmission, residentCount, datasetName);
}
 
// -------------------------------------------------------
// LINKED LIST-BASED Age Group Analysis
// -------------------------------------------------------
void analyseAgeGroupsLinkedList(LinkedList& list, const string& datasetName) {
 
    int    transportCount   [NUM_AGE_GROUPS][NUM_TRANSPORT_MODES] = {};
    double transportEmission[NUM_AGE_GROUPS][NUM_TRANSPORT_MODES] = {};
    double totalEmission    [NUM_AGE_GROUPS]                      = {};
    int    residentCount    [NUM_AGE_GROUPS]                      = {};
 
    Node* current = list.getHead();
 
    while (current != nullptr) {
        Resident r = current->data;
 
        int g = getAgeGroupIndex(r.Age);
        if (g == -1) { current = current->next; continue; }
 
        int t = getTransportIndex(r.ModeOfTransport);
        if (t == -1) { current = current->next; continue; }
 
        double emission = r.DailyDistance * r.CarbonEmissionFactor * r.AverageDayPerMonth;
 
        transportCount   [g][t]++;
        transportEmission[g][t] += emission;
        totalEmission    [g]    += emission;
        residentCount    [g]++;
 
        current = current->next;
    }
 
    printAgeGroupTable(transportCount, transportEmission, totalEmission, residentCount, datasetName);
}
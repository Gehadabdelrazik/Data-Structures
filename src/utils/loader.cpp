#include "loader.h"
#include "../structures/resident.h"
#include "../structures/node.h"
#include <fstream>
#include <sstream>

#include <iostream>

using namespace std;

bool loadDatasetToList(const string& filename, LinkedList& list) {

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "ERROR: Could not open file: " << filename << endl;
        return false;
    }

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        Resident r;

        getline(ss, token, ',');
        r.ResidentID = token;

        getline(ss, token, ',');
        r.Age = stoi(token);

        getline(ss, token, ',');
        r.ModeOfTransport = token;

        getline(ss, token, ',');
        r.DailyDistance = stof(token);

        getline(ss, token, ',');
        r.CarbonEmissionFactor = stof(token);

        getline(ss, token, ',');
        r.AverageDayPerMonth = stoi(token);

        list.insertEnd(r);
    }

    file.close();
    cout << "Loaded (Linked List): " << filename << endl;

    return true;
}

bool loadDataset(const string& filename, ResidentData& dataset) {
 
    // Open the CSV file
    ifstream file(filename);
 
    if (!file.is_open()) {
        cout << "ERROR: Could not open file: " << filename << endl;
        return false;
    }
 
    string line;
 
    // Skip the header row (first line)
    getline(file, line);
 
    // Read each remaining line
    while (getline(file, line)) {
 
        // Skip empty lines
        if (line.empty()) continue;
 
        // Use stringstream to split line by comma
        stringstream ss(line);
        string token;
 
        Resident r;
 
        // Column 1 — ResidentID (string)
        getline(ss, token, ',');
        r.ResidentID = token;
 
        // Column 2 — Age (int)
        getline(ss, token, ',');
        r.Age = stoi(token);
 
        // Column 3 — ModeOfTransport (string)
        getline(ss, token, ',');
        r.ModeOfTransport = token;
 
        // Column 4 — DailyDistance in km (float)
        getline(ss, token, ',');
        r.DailyDistance = stof(token);
 
        // Column 5 — CarbonEmissionFactor in kg CO2/km (float)
        getline(ss, token, ',');
        r.CarbonEmissionFactor = stof(token);
 
        // Column 6 — AverageDayPerMonth (int)
        getline(ss, token, ',');
        r.AverageDayPerMonth = stoi(token);
 
        // Add the resident into the array
        dataset.addResident(r);
    }
    
 
    file.close();
    cout << "Loaded: " << filename
         << " (" << dataset.getSize() << " residents)" << endl;
 
    return true;
}
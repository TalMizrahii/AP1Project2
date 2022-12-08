//
// Created by tal on 12/7/22.
//

#include "FileReader.h"

#define SIZE 13
using namespace std;

FileReader::FileReader() = default;

vector<RelativeVector> FileReader::readFile(string &path) {
    // Create a new stream to read from the file.
    fstream myFile;
    try {
        // Trying to open the file using the path.
        myFile.open(path);
        // If the file is not open, do not proceed.
        if (!myFile.is_open()) {
            throw; // NEED TO BE REPLACED!?
        }
    }
    // Catching an error.
    catch (...) {
        cout << " NO FILE" << endl;
        exit(-1); // NEED TO BE REPLACED!?
    }
    // Declaring a vector of vectors.
    vector<RelativeVector> fileVec;
    // While the file is still ok to read:
    while (myFile.good()) {
        // Create a String to read a full line from the file.
        string fullVector;
        // Get the line from the file and put it in the fullVector.
        getline(myFile, fullVector);
        // Send the line to be processed, and receive back a new relative vector who represent the line.
        RelativeVector dataVec = catchDelim(fullVector);
        // set the new relative vector in the vector of relative vectors.
        fileVec.push_back(dataVec);
    }
    // Return the vector of relative vectors.
    return fileVec;
}


RelativeVector FileReader::catchDelim(const string& toNum) {
    // Create a new stream to go over the line.
    istringstream line(toNum);
    // Initiate a new data vector.
    vector<double> dataVec;
    // Create a new RelativeVector instance.
    RelativeVector relativeMember;
    // Initiate a string to store the data from toNum.
    string fromDelim;
    // Read each data segment seperated by comma.
    while (getline(line, fromDelim, ',')) {
        // Check if the first digit of the number exist or not (.23 or 0.23).
        fromDelim = isDot(fromDelim);
        // If the data extracted from the line is not a number, it must be the specification.
        if (!isdigit(fromDelim[0])) {
            // Set the specification to the RelativeVector and continue.
            relativeMember.setClassification(fromDelim);
            continue;
        }
        // Set the number into the data vector.
        dataVec.push_back(stod(fromDelim));
    }
    // Set the dataVec to the RelativeVector and return it.
    relativeMember.setValuesVector(dataVec);
    return relativeMember;
}

string FileReader::isDot(string toNum) {
    // Check if the first char is a dot.
    if (toNum[0] == '.')
        // If so, concatenate 0 to the number.
        return '0' + toNum;
    // Otherwise just return the number.
    return toNum;
}

FileReader::~FileReader() = default;

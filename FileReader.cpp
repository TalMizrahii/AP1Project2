//
// Created by tal on 12/7/22.
//

#include "FileReader.h"

#define SIZE 13
using namespace std;

FileReader::FileReader() = default;

vector<vector<double>> FileReader::readFile(string &path) {
    fstream myFile;
    try {
        // trying to open the file using the path.
        myFile.open(path);
        if (!myFile.is_open()) {
            throw;
        }
    }
        // Catching an error.
    catch (...) {
        cout << " NO FILE" << endl;
        exit(-1);
    }

    // Declaring a vector of vectors.
    vector<vector<double>> fileVec;
    // While the file is still ok to read:
    while (myFile.good()) {
        // Create a new vector.
        vector<double> dataVec;
        // Read as a string.
        string toNum;
        // Read each data segment.
        while (getline(myFile, toNum, ',')) {
            toNum = isDot(toNum);
            if (!isdigit(toNum[0])) {
                cout << toNum << endl;
                break;
            }
            dataVec.push_back(stod(toNum));
        }
        // When finished with the line, put the vector in the all vector's vector.
        fileVec.push_back(dataVec);
    }

    // Delete!!!!!!!!!!!! test only.
    for (int i = 0; i < fileVec.size(); ++i) {
        for (int j = 0; j < fileVec[i].size(); ++j) {
            cout << fileVec[i][j] << " ";
        }

        cout << "\n-----------------\n" << endl;
    }

    cout << fileVec.size() << endl;

}

string FileReader::isDot(string toNum) {
    if (toNum[0] == '.')
        return '0' + toNum;
    return toNum;
}

FileReader::~FileReader() = default;

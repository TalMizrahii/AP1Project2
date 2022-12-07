//
// Created by tal on 12/7/22.
//

#include "FileReader.h"

#define SIZE 13
using namespace std;

FileReader::FileReader() = default;

vector<vector<double>> FileReader::readFile(string &path) {
    ifstream myFile;
    try{
        // trying to open the file using the path.
        myFile.open(path);
        if (!myFile.is_open()) {
            throw;
        }
    }
    // Catching an error.
    catch (...){
        cout << " NO FILE" << endl;
        exit(-1);
    }

    // Declaring a vector of vectors.
    vector<vector<double>> fileVec;
    // While the file is still ok to read:
    while (myFile.good()) {
        // Create a new vector.
        vector<double> dataVec;
        // Read each data segment.
        for (int i = 0; i < SIZE; ++i) {
            // Read as a string.
            string toNum;
            // Put the data inside num.
            getline(myFile, toNum, ',');
            // Cast to double and put int the vector.
            dataVec.push_back(stod(toNum));
        }
        // When finished with the line, put the vector in the all vector's vector.
        fileVec.push_back(dataVec);
    }

    // Delete!!!!!!!!!!!! test only.
    for (int i = 0; i < fileVec.size(); ++i) {
        for (int j = 0; j < fileVec[i].size(); ++j) {
            cout << fileVec[i][j] << endl;
        }
    }
}

FileReader::~FileReader() = default;

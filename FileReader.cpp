//
// Created by tal on 12/7/22.
//

#include "FileReader.h"

using namespace std;

FileReader::FileReader() {

}

vector<vector<int>> FileReader::readFile(string &path) {
    ifstream myFile(path);
    if (!myFile.is_open()) {
        cout << " NO FILE" << endl;
        exit(-1);
    }

//    myFile.open(path);
    string line = "";
    while (getline(myFile, line)) {
    }
}

FileReader::~FileReader() = default;

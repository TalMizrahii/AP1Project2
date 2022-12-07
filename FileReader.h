//
// Created by tal on 12/7/22.
//

#ifndef AP1PROJECT2_FILEREADER_H
#define AP1PROJECT2_FILEREADER_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;


class FileReader {
public:
    FileReader();

    ~FileReader();

    vector<vector<double>> readFile(string &path);

    string isDot(string toNum);

    void splitBackSlash(string &name, string &nextCube, string toNum1);


};

#endif //AP1PROJECT2_FILEREADER_H

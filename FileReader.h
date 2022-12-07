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
    vector<vector<int>> readFile(string &path);


};

#endif //AP1PROJECT2_FILEREADER_H

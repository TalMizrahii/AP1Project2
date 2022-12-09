#ifndef AP1PROJECT2_FILEREADER_H
#define AP1PROJECT2_FILEREADER_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "RelativeVector.h"

using namespace std;

class FileReader {
public:
    FileReader();

    ~FileReader();

    vector<RelativeVector*> readFile(string &path);

    string isDot(string fullVector);

    RelativeVector* catchDelim(const string &toNum);

};

#endif //AP1PROJECT2_FILEREADER_H

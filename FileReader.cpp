#include "FileReader.h"

using namespace std;

/**
 * A default constructor.
 */
FileReader::FileReader() = default;

/**
 * Reading a csv file line by line and returning a vector of RelativeVectors contain all info about the file's lines.
 * @param path The path to the file.
 * @return A vector of RelativeVectors contain all info about the file's lines.
 */
vector<RelativeVector*> FileReader::readFile(string &path) {
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
    vector<RelativeVector*> fileVec;
    // While the file is still ok to read:
    while (myFile.good()) {
        // Create a String to read a full line from the file.
        string fullVector;
        // Get the line from the file and put it in the fullVector.
        getline(myFile, fullVector);
        // Send the line to be processed, and receive back a new relative vector who represent the line.
        RelativeVector* dataVec = catchDelim(fullVector);
        // Set the new relative vector in the vector of relative vectors.
        fileVec.push_back(dataVec);
    }
    myFile.close();
    // Return the vector of relative vectors.
    return fileVec;
}

/**
 * A method who catch each cell in the line of a cvs file
 * and returns a RelativeVector represent the data about the line.
 * @param fullVector the line from the file as a string.
 * @return RelativeVectors contain all info about the line.
 */
RelativeVector* FileReader::catchDelim(const string &fullVector) {
    // Create a new stream to go over the line.
    istringstream line(fullVector);
    // Initiate a new data vector.
    vector<double> dataVec;
    // Create a new RelativeVector instance.
    auto* relativeMember = new RelativeVector();
    // Initiate a string to store the data from toNum.
    string fromDelim;
    // Read each data segment seperated by comma.
    while (getline(line, fromDelim, ',')) {
        // Check if the first digit of the number exist or not (.23 or 0.23).
        fromDelim = isDot(fromDelim);
        // If the data extracted from the line is not a number, it must be the specification.
        if (!isdigit(fromDelim[0])) {
            // Set the specification to the RelativeVector and continue.
            relativeMember->setClassification(fromDelim);
            continue;
        }
        // Set the number into the data vector.
        dataVec.push_back(stod(fromDelim));
    }
    // Set the dataVec to the RelativeVector and return it.
    relativeMember->setValuesVector(dataVec);
    return relativeMember;
}

/**
 * A method given a number (as a string) checks the need to concatenate 0 to it.
 * @param toNum the number as a string.
 * @return the number concatenated or not.
 */
string FileReader::isDot(string toNum) {
    // Check if the first char is a dot.
    if (toNum[0] == '.')
        // If so, concatenate 0 to the number.
        return '0' + toNum;
    // Otherwise just return the number.
    return toNum;
}

/**
 * A default destructor.
 */
FileReader::~FileReader() = default;
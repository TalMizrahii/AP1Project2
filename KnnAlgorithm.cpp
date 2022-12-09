#include "KnnAlgorithm.h"

/**
 * A default destructor.
 */
KnnAlgorithm::~KnnAlgorithm() = default;

/**
 * A constructor for the class who receives a catalog vector, number k, and a calculation distance object.
 */
KnnAlgorithm::KnnAlgorithm(vector<RelativeVector *> cataloged_vectors1,
                           vector<double> user_vector1,
                           int k_neighbors1,
                           AbstractDistance *calculation) {
    // Calling the setters.
    seCalc(calculation);
    setCataloged_vectors(std::move(cataloged_vectors1));
    setUserVector(std::move(user_vector1));
    setKNeighbors(k_neighbors1);
}

/**
 * Setter for cataloged_vectors.
 * @param catalogedVectors The vector of all RelativeVectors.
 */
void KnnAlgorithm::setCataloged_vectors(vector<RelativeVector *> cataloged_vectors1) {
    this->catalogedVectors = std::move(cataloged_vectors1);
}

/**
 * Setter for userVector.
 * @param userVector The user's vector.
 */
void KnnAlgorithm::setUserVector(vector<double> user_vector1) {
    this->userVector = std::move(user_vector1);
}

/**
 * Setter for the kNeighbors.
 * @param kNeighbors The k number.
 */
void KnnAlgorithm::setKNeighbors(int k_neighbors1) {
    this->kNeighbors = k_neighbors1;
}

/**
 * Setter for the calculation formula.
 * @param calculation1 The calculation formula.
 */
void KnnAlgorithm::seCalc(AbstractDistance *calculation1) {
    this->calc = calculation1;
}

/**
 * A getter for the k number.
 * @return the k number.
 */
int KnnAlgorithm::getKNeighbors() const {
    return this->kNeighbors;
}

/**
 * A double for the user's vector.
 * @return The user's vector.
 */
vector<double> KnnAlgorithm::getUserVector() {
    return this->userVector;
}

/**
 * A getter for the catalog vector.
 * @return The catalog vector.
 */
vector<RelativeVector *> KnnAlgorithm::getCatalogedVectors() {
    return catalogedVectors;
}

/**
 * A getter for the calculation member.
 * @return The calculation member.
 */
AbstractDistance *KnnAlgorithm::getCalc() {
    return this->calc;
}

/**
 * The function check if the vectors we created have the same size.
 * @param v1 the vector we created from the user input.
 * @param v2 the vector we created from the user input.
 */
void KnnAlgorithm::sizeComparison(const vector<double> &v1, const vector<double> &v2) {
    // Checking if the vectors have the same size.
    if (v1.size() != v2.size()) {
        cout << "The vectors are not equally sized." << endl;
        exit(-1);
    }
}

/**
 * Calculate the distance between all vectors to the userVector and set them the result.
 */
void KnnAlgorithm::calculateDistances() {
    // This for loop calc the distance between userVector(user input) to all the cataloged vectors.
    for (int i = 0; i < getCatalogedVectors().size(); i++) {
        // Checking if the vectors in the same size.
        sizeComparison(getCatalogedVectors()[i]->getValuesVector(), getUserVector());
        // Set the result of the distance between the user's vector to the ith vector.
        double result = getCalc()->calculateDistance(getCatalogedVectors()[i]->getValuesVector(), getUserVector());
        // Set the result to the ith vector.
        getCatalogedVectors()[i]->setDistanceFromRelativeVec(result);
    }
}

/**
 * A comparator for the sort function between to RelativeVectors by their distance value.
 * @param v1 The first RelativeVector.
 * @param v2 The second RelativeVector.
 * @return True if the distance of v1's distance is lower then v2's, False otherwise.
 */
bool compareRelativeVector(RelativeVector *v1, RelativeVector *v2) {
    return (v1->getDistanceFromRelativeVec() < v2->getDistanceFromRelativeVec());
}

/**
 * Sorting the vector of RelativeVectors, taking only the first k elements.
 * @return A vector of the k smallest by distance elements.
 */
vector<RelativeVector *> KnnAlgorithm::sortingAndGettingK() {
    // Set the CatalogVectors to a temp vector.
    vector<RelativeVector *> knn = getCatalogedVectors();
    // Sort the array by the given compare function.
    sort(knn.begin(), knn.end(), compareRelativeVector);
    // Set the knn to the catalog vector.
    setCataloged_vectors(knn);
    // Create a new vector.
    vector<RelativeVector *> kRelativeVectors;
    // Push to it the first k elements.
    for (int i = 0; i < getKNeighbors(); i++) {
        cout << knn[i]->getDistanceFromRelativeVec() << endl;
        kRelativeVectors.push_back(knn[i]);
    }
    // Return the first k elements.
    return kRelativeVectors;
}

string KnnAlgorithm::classificationUserVec() {
    calculateDistances();
    vector<RelativeVector *> nearestK = sortingAndGettingK();

    return "";
}
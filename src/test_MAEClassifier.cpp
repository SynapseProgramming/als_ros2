#include <cassert>
#include <vector>

// Include the header file for the MAEClassifier class
#include "als_ros2/MAEClassifier.h"

using namespace als_ros2;

// Define a test function
void testMAEClassifier()
{
    // Create an instance of the MAEClassifier class
    MAEClassifier classifier;

    // Set the classifier directory
    classifier.setClassifierDir("/home/roald/ros2_ws/src/als_ros2/classifiers/MAE/");

    // Set the maximum residual error
    classifier.setMaxResidualError(1.0);

    // Set the MAE histogram bin width
    classifier.setMAEHistogramBinWidth(0.01);

    // // Define some test data for training
    std::vector<std::vector<double>> trainSuccessResidualErrors = {
        {0.1, 0.2, 0.3},
        {0.4, 0.5, 0.6}
    };
    std::vector<std::vector<double>> trainFailureResidualErrors = {
        {1.1, 1.2, 1.3},
        {1.4, 1.5, 1.6}
    };

    // // Learn the failure threshold
    // classifier.learnThreshold(trainSuccessResidualErrors, trainFailureResidualErrors);

    // // Define some test data for evaluation
    std::vector<std::vector<double>> testSuccessResidualErrors = {
        {0.1, 0.2, 0.3},
        {0.4, 0.5, 0.6}
    };
    std::vector<std::vector<double>> testFailureResidualErrors = {
        {1.1, 1.2, 1.3},
        {1.4, 1.5, 1.6}
    };

    // // Write the classifier parameters
    // classifier.writeClassifierParams(testSuccessResidualErrors, testFailureResidualErrors);

    // // Read the classifier parameters
    classifier.readClassifierParams();

    // // Perform assertions to validate the results
    assert(classifier.getFailureThreshold() > 0.0);
    assert(classifier.getMAE(testSuccessResidualErrors[0]) >= 0.0);
    assert(classifier.getMAE(testFailureResidualErrors[0]) >= 0.0);
}

// Define the main function to run the tests
int main()
{
    testMAEClassifier();
    return 0;
}
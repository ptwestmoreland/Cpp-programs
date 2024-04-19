#include <iostream>
#include <Eigen/Dense>
using namespace Eigen; // eigen is a linear algrbra lib
using namespace std;

double resistorValue(double v, double i, VectorXd& phi)
{
    VectorXd X(2); // creates vector from v and i
    X << v, i;
    double predictResistor = phi.dot(X); // dot product member function
    return predictResistor;
} // end prediction function

int main() {
    MatrixXd trainingData(3, 2); // 3x2 training matrix, v and i data
    trainingData <<
    5.0, 2.0
    ,10.0, 1.5,
    7.0, 3.0;

    VectorXd resistors(3); // small resistor value data set
    resistors << 2.5, 6.67, 2.33;
    // l;inear regression
    VectorXd phi = trainingData.transpose().fullPivLu().solve(resistors);
    double sampleVoltage = 8.0;
    double sampleCurrent = 2.5;
    double predictedResistor = resistorValue(sampleVoltage, sampleCurrent, phi);

    // Display the predicted resistor value
   double predictedResist = resistorValue(sampleVoltage, sampleCurrent, phi);
   cout << "Predicted resistor is: " << predictedResist << endl;


    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>

using namespace std;

constexpr int NO_TEMPS = 10;

int main (int argc, char * argv[])
{
    char delim = '\n';
    std::default_random_engine d_engine{};
    std::normal_distribution<> temp_dist{32, 2};
    vector <double> ftemps;
    int j = 0;
    int i = 0;
    for (int i = 1; i <= NO_TEMPS; ++i) {
        ftemps.push_back(temp_dist(d_engine));
    }
    vector<double> ctemps;
    double ctemp;
    for (decltype(ftemps.size()) j = 0; j < ftemps.size(); ++j) {
         ctemp = ( (ftemps.at(j) - 32.0) * (5.0 / 9.0) );
        ctemps.push_back(ctemp);
        //cout << "[" << i << "]" << " " << ftemps.at(i) << " to " << ctemps.at(i) << delim;
    }
    double min = ctemps.at(0);
    double max = ctemps.at(0);
    //cout.precision(5);
    //double roundedftemp = 0.0;
    //double roundedctemp = 0.0;
    for (decltype(ctemps.size()) i = 0; i < ctemps.size(); ++i) {
        if (min > ctemps.at(i)) {
            min = ctemps.at(i);
        }
        if (max < ctemps.at(i)) {
            max = ctemps.at(i);
        }
          //roundedftemp = (int)(ftemps.at(i) * 1000.0)/1000.0;
         // roundedctemp = (int)(ctemps.at(i) * 1000.0)/1000.0;

    cout << "[" << i << "]" << " " << std::fixed << std::setprecision(3) << ftemps.at(i) << " to "  << std::fixed << std::setprecision(3) << ctemps.at(i) << delim;


    }


  //  double roundedMax = (int)(max * 1000.0) / 1000.0;
   // double roundedMin = (int)(min * 1000.0) / 1000.0;

cout << "Max Temp (in celsius) : " << std::fixed << std::setprecision(3) << max << '\t' << "Min Temp (in celsius) : " << std::fixed << std::setprecision(3) << min << endl;
    return 0;
}

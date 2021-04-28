#ifndef __WOA_H__
#define __WOA_H__

#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
#include <fstream>
using namespace std;



class WOA{
    int iter;
    int dim;
    int runs;
    int pop_num;
    double ub;
    double lb;

    double b;

    typedef vector<double> sol;
    typedef vector<sol> pop;

public:
    WOA(int Iteration, int Dimension, int Runs, int Population, double upper_bound, double lower_bound, double Spiral);
    void run();

};

#endif
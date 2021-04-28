#ifndef __PSO_H__
#define __PSO_H__

#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
#include <fstream>
using namespace std;



class PSO{
    int iter;
    int dim;
    int runs;
    int pop_num;
    double inertia;
    double c1;
    double c2;
    double ub;
    double lb;

    typedef vector<double> sol;
    typedef vector<sol> pop;

public:
    PSO(int Iteration, int Dimension, int Runs, int Population, double upper_bound, double lower_bound, double inertia, double c1, double c2);
    void run();

};

#endif
#include "WOA.h"

int main(int argc, char **argv){
    int Iteration = atoi(argv[1]);
    int Dimension = atoi(argv[2]);
    int Runs = atoi(argv[3]);
    int Population = atoi(argv[4]);
    double upper_bound = atof(argv[5]);
    double lower_bound = atof(argv[6]);
    double Spiral = atof(argv[7]);

    WOA woa(Iteration, Dimension, Runs, Population, upper_bound, lower_bound, Spiral);
    woa.run();

}
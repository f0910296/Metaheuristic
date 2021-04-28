#include "PSO.h"

int main(int argc, char **argv){
    int Iteration = atoi(argv[1]);
    int Dimension = atoi(argv[2]);
    int Runs = atoi(argv[3]);
    int Population = atoi(argv[4]);
    double upper_bound = atof(argv[5]);
    double lower_bound = atof(argv[6]);
    double inertia = atof(argv[7]);
    double c1 = atof(argv[8]);
    double c2 = atof(argv[9]);

    PSO pso(Iteration, Dimension, Runs, Population, upper_bound, lower_bound, inertia, c1, c2);
    pso.run();

}
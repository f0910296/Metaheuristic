#include "PSO.h"
#include "../lib.h"

PSO::PSO(int Iteration, int Dimension, int Run, int Population, double upper_bound, double lower_bound, double inertia, double c1, double c2):
        iter(Iteration), dim(Dimension), runs(Run), pop_num(Population), ub(upper_bound), lb(lower_bound), inertia(inertia), c1(c1), c2(c2){        
    srand(time(NULL));
}

void PSO::run(){ // The main function of PSO.

    LIB lib(dim, pop_num, ub, lb); // Dimension, Population, upper_bound, lower_bound
    double avg = 0;
    sol Average = sol(iter);

    ofstream File;
    File.open("PSO.txt");

    for(int r=0; r<runs; ++r){
        //Initialization
        pop X = lib.Init_pop();
        pop V = lib.Init_pop();
        sol X_pbest = sol(dim);
        sol X_gbest = sol(dim);
        
        double best = numeric_limits<double>::infinity();

        for(int i=0; i<iter; ++i){
            // Decide personal best and global best.
            double pbest = numeric_limits<double>::infinity();
            for(int p=0; p<pop_num; ++p){
                double temp = lib.F10(X[p]);
                if(pbest>temp){
                    pbest = temp;
                    X_pbest = X[p];
                    if(best>pbest){
                        best = temp;
                        X_gbest = X[p];
                    }
                }
                
            } // End of population

            for(int p=0; p<pop_num; ++p){
                for(int d=0; d<dim; ++d){
                    double r1 = (double) (rand()%RAND_MAX)/RAND_MAX;
                    double r2 = (double) (rand()%RAND_MAX)/RAND_MAX;

                    V[p][d] =  inertia * V[p][d] + c1 * r1 * (X_pbest[d]-X[p][d]) + c2 * r2 * (X_gbest[d]-X[p][d]);
                    X[p][d] += V[p][d];
                }

                // Check boundary
                X[p] = lib.Check_bound(X[p]);
                V[p] = lib.Check_bound(V[p]);
                X_pbest = lib.Check_bound(X_pbest);
                X_gbest = lib.Check_bound(X_gbest);

            } // End of population
            Average[i] += best;
            
        } // End of iteration
        cout << "Best: " << best << endl;
        avg += best;
    } // End of run

    for(int i=0; i<iter; ++i)
        File << i+1 << " " << Average[i]/runs << endl;
    File.close();
  
    avg /= runs;
    cout << "Average fitness: " << avg << endl;
}

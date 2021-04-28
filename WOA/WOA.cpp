#include "WOA.h"
#include "../lib.h"

WOA::WOA(int Iteration, int Dimension, int Run, int Population, double upper_bound, double lower_bound, double Spiral):
        iter(Iteration), dim(Dimension), runs(Run), pop_num(Population), ub(upper_bound), lb(lower_bound), b(Spiral){        
    srand(time(NULL));
}

void WOA::run(){ // The main function of WOA.

    LIB lib(dim, pop_num, ub, lb); // Dimension, Population, upper_bound, lower_bound

    double avg = 0;
    sol Average = sol(iter);

    ofstream File;
    File.open("WOA.txt");
    
    for(int r=0; r<runs; ++r){
        //Initialization
        pop X = lib.Init_pop();
        sol X_best = sol(dim, ub);
        double best = numeric_limits<double>::infinity();

        // Calculate the best s
        for(int p=0; p<pop_num; ++p){
            double temp = lib.F10(X[p]);
            if(best > temp){
                X_best = X[p];
                best = temp;
            }
        }
        
        for(int i=0; i<iter; ++i){
            double a = (double)2*(iter-i)/iter;
            for(int p=0; p<pop_num; ++p){

                // Update a, A, C, l, and prob
                sol r = sol(dim);
                sol A = sol(dim);
                sol C = sol(dim);
                sol l = sol(dim);
                for(int d=0; d<dim; ++d){
                    r[d] = (double)rand()/RAND_MAX;
                    A[d] = 2*a*r[d]-a;
                    C[d] = 2*r[d];
                    l[d] = ((double)rand()/RAND_MAX)*2-1;
                } // End of population

                double prob = (double)rand()/RAND_MAX;
                for(int d=0; d<dim; ++d){
                    if(prob<0.5){ 
                        if(A[d]>1){
                            int rand_p = rand()%pop_num;
                            double D = C[d] * X[rand_p][d] - X[p][d];
                            D = fabs(D);
                            X[p][d] = X[rand_p][d] - A[d]*D;
                        }
                        else{
                            double D = C[d] * X_best[d] - X[p][d];
                            D = fabs(D);
                            X[p][d] = X_best[d] - A[d]*D;
                        }
                    }
                    else{
                        double D = X_best[d] - X[p][d];
                        D = fabs(D);
                        X[p][d] = D * exp(b*l[d]) * cos(2*M_PI*l[d]) + X_best[d];
                    }
                } // End of dimension

                // Check boundary
                X[p] = lib.Check_bound(X[p]);
            
            } // End of population
                        
            // Update best solution
            for(int p=0; p<pop_num; p++){
                double temp = lib.F10(X[p]);
                if(best > temp){
                    X_best.clear();
                    X_best = X[p];
                    best = temp;
                }
            }
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
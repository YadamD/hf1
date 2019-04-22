#include <iostream>
#include "matrix.h"
#include <random>
#include <chrono>
#include <fstream>
#include <cmath>

using namespace std;

int main(int, char**){
    cout.precision(16);
    unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
    minstd_rand0 generator(seed);
    vector<double> time_r;
    vector<double> N(1000);
    for(int dim = 2; dim < 1001; dim++){
        int n = dim*dim;
        N[dim-2] = n;
        vector<double> matrix1(n);
        vector<double> matrix2(n);
        for(int j = 0; j < n; j++){
            matrix1[j] = generator()/(1e5);
            matrix2[j] = generator()/(1e5);
        }
        sq_matrix<double> m1(dim, matrix1);
        sq_matrix<double> m2(dim, matrix2);

        auto t_0 = std::chrono::high_resolution_clock::now();
        sq_matrix<double> m_prod = move(m1)*m2; 
        auto t_1 = std::chrono::high_resolution_clock::now();
        double t_r =(static_cast<std::chrono::duration<double,std::milli>>(t_1-t_0)).count();
        time_r.push_back(t_r);
    }
    ofstream f;
    f.open("timedata.txt", fstream::app);
    for(int i = 0; i < static_cast<int>(N.size())-1; i++){
    f << N[i] << ", " << time_r[i] << "\n";
    }
    f.close();
    return 0;
}

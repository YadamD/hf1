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
    std:: vector<double> time_r;
    std:: vector<double> N;
    for(int dim = 2; dim < 1001; dim++){
        std::vector<double> matrix1;
        std::vector<double> matrix2;
        for(int j = 0; j < dim*dim; j++){
            matrix1.push_back(generator()/(1e5+0.0));
        }
        for(int j = 0; j < dim*dim; j++){
            matrix2.push_back(generator()/(1e5+0.0));
        }
        N.push_back(dim*dim);
        sq_matrix<double> m1(dim, matrix1);
        sq_matrix<double> m2(dim, matrix2);

        auto t_0 = std::chrono::high_resolution_clock::now();
        sq_matrix<double> m_prod = move(m1)*m2; 
        auto t_1 = std::chrono::high_resolution_clock::now();
        double t_r =(static_cast<std::chrono::duration<double,std::milli>>(t_1-t_0)).count();
        time_r.push_back(t_r);
    }
    ofstream f;
    f.open("timedata.txt",fstream::app);
    for(int i = 0; i < static_cast<int>(N.size())-1; i++){
    f << N[i] << ", " << time_r[i] << "\n";
    }
    f.close();
    return 0;
}

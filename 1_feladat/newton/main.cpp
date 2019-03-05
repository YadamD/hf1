#include <iostream>
#include <cmath>

double sqrt_newton(double num, double x0){
    if(num <= 0){
        exit(-1);
    }
    double root_it = 0;
    for(int i = 0; i < 10; i++){
        root_it = x0 - ((x0 * x0 - num)/(2*x0));
        x0 = root_it;
    }
    return root_it;
}

int main() {
    double root = sqrt_newton(10,1);
    std::cout<< root;
    root = sqrt_newton(-10,1);
    std::cout<< root;
}

#include <iostream>
#include <math.h>

double sqrt_newton(double num, double x0){
double root_it;
    for(int i = 0; i < 10; i++){
       root_it = x0 - ((x0 * x0 - num)/(2*x0));
       x0 = root_it;
    }
    return root_it;
}

int main(int, char**) {
    double root = sqrt_newton(10,1);
    std::cout<< root;
}

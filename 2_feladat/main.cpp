#include <iostream>
#include <string>
#include <cmath>

using namespace std;

static double epsilon = 1e-5;
static int max_step = 20;

template <typename T, typename F1, typename F2, typename F3>

T newton(F1 func, F2 f_der, F3 check, T x0){
    if(!check(0,x0)){
        cout<<"Initial guess error!"<<endl;
        exit(-1);
    }
    T prev = 0;
    int counter = 0;
    while(check(prev,x0) && counter < max_step){
        prev = x0;
        x0 = x0 - f(x0) / f_der(x0);
        counter++;
    }
    return x0;
}

auto check = [](double a, double b ){ return abs(a - b) > epsilon; };
auto f = [](double x){ return x*x - 612.0; };
auto f_der = [](double x){ return 2.0 * x; };

int main()
{
    cout.precision(16);
    double sol = newton(f, f_der, check, 10.0);
    cout << "Root of 612: "<<'\n'<< sol << endl;
    cout << "Error: "<< abs(sol - 24.7386337537059632) << endl;
    sol = newton(f, f_der, check, 1.0);
    cout << "Root of 612: "<<'\n'<< sol << endl;
    cout << "Error: "<< abs(sol - 24.7386337537059632) << endl;
    sol = newton(f, f_der, check, 1e-6);
    cout << "Root of 612: "<<'\n'<< sol << endl;
    cout << "Error: "<< abs(sol - 24.7386337537059632) << endl;
    return 0;
}

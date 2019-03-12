#include <iostream>
#include <vector>
#include <array>
#include <numeric>

using namespace std;

array <double, 2> linear_fit(vector<double> const& x, vector<double> const& y){
    if(static_cast<int>(x.size()) != static_cast<int>(y.size())){
        cout<<"Data error, x and y must have same dimension! \n"<<endl;
        return {0,0};
    }
    double x_av = accumulate(x.begin(),x.end(), 0.0)/static_cast<double>(x.size());
    double y_av = accumulate(y.begin(),y.end(), 0.0)/static_cast<double>(y.size());
    auto f_den = [x_av](double a_0, double a_1){ return a_0 + (a_1 - x_av) * (a_1 - x_av);};
    double denom = accumulate(x.begin(),x.end(), 0.0, f_den);
    if(denom == 0.0){
        cout<<"Error: division by zero \n"<<endl;
        return {0,0};
    }
    double num = 0;
    for(int i = 0; i < static_cast<int>(x.size()); i++){
        num += (x[i] - x_av) * (y[i] - y_av);
    }
    return {num / denom, y_av - x_av * (num / denom)};
}

int main(){
    cout.precision(10);
    //Test cases:
    vector <double> const x_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector <double> const y_1 = {2649,2624,469,5079,7060,8153,2532,8681,6691};
    vector <double> const y_2 = {0};
    vector <double> const y_3 = {-1.2378, -5.408, -1.454586, -2.0, -1.982, -3.002, 0.0012, -3.045, -2.7};
    array <double, 2> fit = linear_fit(x_1,x_1);
    double m = fit[0]; 
    double b = fit[1];
    cout<<"Fitted parameters:\n"<<"m = "<<m<<'\n'<<"b = "<<b<<'\n'<<endl;
    cout<<"Correct values: \n"<<"m = 1,  b = 0 \n"<<endl;
    fit = linear_fit(x_1,y_1);
    m = fit[0]; 
    b = fit[1];
    cout<<"Fitted parameters:\n"<<"m = "<<m<<'\n'<<"b = "<<b<<'\n'<<endl;
    cout<<"Correct values: \n"<<"m = 692.3166667,  b = 1420.416667 \n"<<endl;
    fit = linear_fit(x_1,y_2);
    m = fit[0]; 
    b = fit[1];
    cout<<"Fitted parameters:\n"<<"m = "<<m<<'\n'<<"b = "<<b<<'\n'<<endl;
    cout<<"Correct values: None, fitting error! \n"<<endl;
    fit = linear_fit(x_1,y_3);
    m = fit[0]; 
    b = fit[1];
    cout<<"Fitted parameters:\n"<<"m = "<<m<<'\n'<<"b = "<<b<<'\n'<<endl;
    cout<<"Correct values: \n"<<"m = 0.0524962,  b = -2.576723889 \n"<<endl;
    return 0;
}

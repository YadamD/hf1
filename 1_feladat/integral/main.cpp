#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

double midpoint(int n, double x0, double x1) {
	if(n<=0){
		exit(-1);
	}
	if(x0 > x1){
		swap(x0, x1);
	}
	double h = (x1 - x0) / double(n + 2), res = 0;
	for( int i = 0; i <= n / 2; i++){
    	double x =  (i * 2 + 1) * h + x0;
    	double func = cos(x) * exp(-x*x);
    	res += func;
	}
	return 2 * h * res;
}

int main() {
    cout.precision(16);
	double result;
	double x_0 = -1, x_1 = 3;
    for(int i = 0; i < 6; i++){
	    result = midpoint(int(pow(10,i+2)), x_0, x_1);
	    cout<<"n = "<<pow(10,i+2)<<'\n'<<result<<endl;
        cout<<"Eltérés a helyes értéktől: "<<result-1.3463879568034503<<endl;
    }
    cout<<"Helyes ertek: 1.346387956803450376698" <<endl;
    x_0 = 0; 
    x_1 = 100;
    result = midpoint(10000000, x_0, x_1);
	cout<<'\n'<<result<<endl;
	cout<< "Helyes ertek: 0.69019422352157148738"<<endl;
    cout <<"Különbség:"<<result-0.6901942235215714<<endl;
	x_0 = 100;
	x_1 = -100;
    result = midpoint(0, x_0, x_1);
	cout <<'\n'<<result<<endl;
	cout << "Helyes ertek: 1.38038844704314297477341" <<endl;
    cout <<"Különbség:"<<result-1.3803884470431429<<endl;
  return 0;
}

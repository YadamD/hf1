#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double midpoint(int n, double x0, double x1) {
	double h, x, func, res = 0;
	h = (x1 - x0) / double(n + 2);
	for(int i = 0; i < (n / 2) + 1; i++){
    	x =  (i * 2 + 1) * h + x0;
    	func = cos(x) * exp(-1*x*x);
    	res += func;
	}
	return (2 * h * res);
}

int main() {
	/*cout << "Also integralasi hatar: ";
	cin >> x_0;
	cout << "Felso integralasi hatar: ";
	cin >> x_1;*/
	double result;
	double x_0 = -1, x_1 = 3;
    for(int i = 0; i < 6; i++){
	    result = midpoint(pow(10,i+2), x_0, x_1);
	    cout <<"n = "<<pow(10,i+2)<<'\n'<<result<<cout.precision(16)<<endl;
    }
    cout << "Helyes ertek: 1.346387956803450376698" << '\n' <<"Ez 14 tizedesjegyre pontos."<<endl;
    x_0 = 0; 
    x_1 = 100;
    result = midpoint(10000000, x_0, x_1);
	cout <<'\n'<<result<<cout.precision(16)<<endl;
	cout << "Helyes ertek: 0.69019422352157148738" << '\n'<<endl;
	x_0 = -100;
	x_1 = 100;
    result = midpoint(10000000, x_0, x_1);
	cout <<'\n'<<result<<cout.precision(16)<<endl;
	cout << "Helyes ertek: 1.38038844704314297477341" << '\n'<<endl;
  return 0;
}

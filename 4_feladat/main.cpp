#include <iostream>
#include <string>
#include "vector2.h"

using namespace std;

int main(){
    cout.precision(7);
    vec2<double> const v1 = {1.0, 2.0};
    vec2<double> const v2 = {987.654, 123.456};
    vec2<double> v3 = v1;
    vec2<double> v4 = v2;
    cout<<v1 + v2<<endl;
    cout<<"Correct value : [988.654, 125.456]"<<'\n'<<endl;
    cout<<v1 - v2<<endl;
    cout<<"Correct value : [-986.654, -121.456]"<<'\n'<<endl;
    cout<<v2 * 3<<endl;
    cout<<"Correct value : [2962.962, 370.368]"<<'\n'<<endl;
    cout<<4.5 * v2<<endl;
    cout<<"Correct value : [4444.443, 555.552]"<<'\n'<<endl;
    cout<<v2 / 987.654<<endl;
    cout<<"Correct value : [1.0, 0.1249992]"<<'\n'<<endl;
    cout<<dot(v1,v2)<<endl;
    cout<<"Correct value : 1234.566"<<'\n'<<endl;
    cout<<length(v1)<<endl;
    cout<<"Correct value : 2.236068"<<'\n'<<endl;
    cout<<sqlenght(v1)<<endl;
    cout<<"Correct value : 5"<<'\n'<<endl;
    cout<<normalize(v2)<<endl;
    cout<<"Correct value : [0.992278, 0.124034]"<<'\n'<<endl;
    v3 += v4;
    cout<<v3<<endl;
    cout<<"Correct value : [988.654, 125.456]"<<'\n'<<endl;
    v3 -= v4;
    cout<<v3<<endl;
    cout<<"Correct value : [1.0, 2.0]"<<'\n'<<endl;
    v3 = v1;
    v3 *= 2;
    cout<<v3<<endl;
    cout<<"Correct value : [2.0, 4.0]"<<'\n'<<endl;
    v3 /= 2;
    cout<<v3<<endl;
    cout<<"Correct value : [1.0, 2.0]"<<'\n'<<endl;
    vec2<double> v5 = {0.0, 0.0};
    cin>>v5;
    cout<<"The vector: "<<v5<<endl;
    return 0;
}

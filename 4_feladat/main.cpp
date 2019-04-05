#include <iostream>
#include <string>
#include "vector2.h"
#include <vector>
using namespace std;

bool dbeq(double a, double b, double eps){
    if(std::abs(a-b) < eps){
        return true;
    }
    return false;
}

int main(){
    cout.precision(7);
    vec2<double> const v1 = {1.0, 2.0};
    vec2<double> const v2 = {987.654, 123.456};
    vec2<double> v3 = v1;
    vec2<double> v4 = v2;
    double const epsilon = 1e-10;

    vector<vec2<double>> sol_v= {{988.654, 125.456}, {-986.654, -121.456}, {2962.962, 370.368}, {2962.962, 370.368},
    {4444.443, 555.552}, {1.0, 0.1249992406247532030},{0.9922779694532460, 0.12403399267032780}};
    vector<vec2<double>> test_v = {v1 + v2, v1 - v2, v2 * 3, 3 * v2, 4.5 * v2, v2 / 987.654, normalize(v2)};

    for(int i = 0; i < static_cast<int>(sol_v.size()); i++){
        if(!(sol_v[i] == test_v[i])){
            cout<<"Error! vector["<< i << "]" <<endl;
        }
    }

    vector<double> sol_v2 = {1234.566, 2.23606797749978969, 5};
    vector<double> test_v2 = {dot(v1,v2), length(v1), sqlength(v1)};

    for(int i = 0; i < static_cast<int>(sol_v2.size()); i++){
        if(!dbeq(sol_v2[i], test_v2[i], epsilon)){
            cout<<"Error! double["<< i <<"]"<<endl;
        }
    }

    v3 += v4;
    vec2<double> const sol1 = {988.654, 125.456};
    if(v3 != sol1){
        cout<<"Error in += operator"<<endl;
    }

    v3 -= v4;
    vec2<double> const sol2 = {1.0, 2.0};
    if(v3 != sol2){
        cout<<"Error in -= operator"<<endl;
    }

    v3 = v1;
    v3 *= 2;
    vec2<double> const sol3 = {2.0, 4.0};
    if(v3 != sol3){
        cout<<"Error in *= operator"<<endl;
    }

    v3 /= 2;
    vec2<double> const sol4 = {1.0, 2.0};
    if(v3 != sol4){
        cout<<"Error in /= operator"<<endl;
    }

    vec2<double> v5 = {0.0, 0.0};
    cout<<"Set vector elements:"<<'\n'<<endl;
    cin>>v5;
    cout<<"The vector: "<<v5<<endl;

    return 0;
}

#include <iostream>
#include <string>
#include "matrix.h"
#include <array>
using namespace std;

int main(){
    cout.precision(7);
    sq_matrix<double>  const m1 = {821,13,463,215,992,708,880,12,974,79,564,829,95,568,63,149};
    sq_matrix<double>  const m2 = {567,573,840,105,223,289,169,928,831,788,661,261,59,809,449,49};
    double eps = 1e-10;
    cout<<m1<<endl;
    //Correct values from https://matrix.reshish.com
    if(!sq_matrix_eq(m1, m1, eps)){
        cout<<"Error in equality check function!"<<endl;
    }    
    if(sq_matrix_eq(m1, m2, eps)){
        cout<<"Error in equality check function!"<<endl;
    } 

    sq_matrix<double> a1 = m1 + m2;
    sq_matrix<double> const add_res = {1388,586,1303,320,1215,997,1049,940,1805,867,1225,1090,154,1377,512,198};
    if(!sq_matrix_eq(a1, add_res, eps)){
        cout<<"Addition operator error!"<<endl;
        cout<<a1<<endl;
        cout<<add_res<<endl;
    }
    sq_matrix<double> a2 = m1 - m2;
    sq_matrix<double> const sub_res  = {254,-560,-377,110,769,419,711,-916,143,-709,-97,568,36,-241,-386,100};
    if(!sq_matrix_eq(a2, sub_res, eps)){
        cout<<"Substraction operator error!"<<endl;
        cout<<a2<<endl;
        cout<<sub_res<<endl;;        
   }

    sq_matrix<double> a3 = m1 * m2;
    sq_matrix<double> const prod_res1  = {865844,1012969,1094415,229647,1452336,1476176,1540000,991452,1087470,1696026,1576536,363407,241673,388772,284336,560823};
    if(!sq_matrix_eq(a3, prod_res1, eps)){
        cout<<"Matrix product error!";
        cout<<a3<<endl;
        cout<<prod_res1<<endl;; 
    }
    return 0;
}

#include <iostream>
#include <string>
#include "matrix.h"
#include <array>
using namespace std;

int main(){
    cout.precision(7);
    sq_matrix<double> const m1 = {821,13,463,215,992,708,880,12,974,79,564,829,95,568,63,149};
    sq_matrix<double> const m2 = {567,573,840,105,223,289,169,928,831,788,661,261,59,809,449,49};
    sq_matrix<double> m3 = m2;
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
        cout<<"Matrix product1 error!";
        cout<<a3<<endl;
        cout<<prod_res1<<endl;; 
    }

    sq_matrix<double> a4 = m2 * m1;
    sq_matrix<double> const prod_res2  = {1862058, 539055, 1247136, 840786, 722537, 747966, 511349, 329786, 2132556, 769174, 1467440, 774979, 1292948, 636842, 995560, 401915};
        if(!sq_matrix_eq(a4, prod_res2, eps)){
        cout<<"Matrix product2 error!"<<endl;
        cout<<a4<<endl;
        cout<<prod_res2<<endl;; 
    }

    sq_matrix<double> a5 = m2 * 2.2;
    sq_matrix<double> const mul1  = {1247.4, 1260.6, 1848, 231, 490.6, 635.8, 371.8, 2041.6, 1828.2, 1733.6, 1454.2, 574.2, 129.8, 1779.8, 987.8, 107.8};
    if(!sq_matrix_eq(a5, mul1, eps)){
        cout<<"Matrix multiplication1 error!"<<endl;
        cout<<a5<<endl;
        cout<<mul1<<endl;; 
    }

    sq_matrix<double> a6 = 2.2 * m2;    
    if(!sq_matrix_eq(a6, mul1, eps)){
        cout<<"Matrix multiplication2 error!"<<endl;
        cout<<a6<<endl;
        cout<<mul1<<endl;; 
    }

    sq_matrix<double> a6d = m2/100;    
    sq_matrix<double> div = {5.67, 5.73, 8.4, 1.05, 2.23, 2.89, 1.69, 9.28, 8.31, 7.88, 6.61, 2.61, 0.59, 8.09, 4.49, 0.49};
    if(!sq_matrix_eq(a6d, div, eps)){
        cout<<"Matrix division error!"<<endl;
        cout<<a6d<<endl;
        cout<<div<<endl;; 
    }

    sq_matrix<double> a7 = m1 + std::move(m3);
    if(!sq_matrix_eq(a7, add_res, eps)){
        cout<<"Addition operator error! (move2)"<<endl;
        cout<<a7<<endl;
        cout<<add_res<<endl;
    }
    sq_matrix<double> m4 = m2;
    sq_matrix<double> a8 = std::move(m4) + m1;
    if(!sq_matrix_eq(a8, add_res, eps)){
        cout<<"Addition operator error! (move1)"<<endl;
        cout<<a8<<endl;
        cout<<add_res<<endl;
    }

    sq_matrix<double> m5 = m1;
    sq_matrix<double> m6 = m2;
    sq_matrix<double> a9 = std::move(m5) + std::move(m6);
    if(!sq_matrix_eq(a9, add_res, eps)){
        cout<<"Addition operator error! (move_both)"<<endl;
        cout<<a9<<endl;
        cout<<add_res<<endl;
    }

    sq_matrix<double> m7 = m1;
    sq_matrix<double> m8 = m2;
    sq_matrix<double> a10 = std::move(m7) - std::move(m8);
    if(!sq_matrix_eq(a10, sub_res, eps)){
        cout<<"Substraction operator error! (move_both)"<<endl;
        cout<<a10<<endl;
        cout<<sub_res<<endl;
    }

    sq_matrix<double> m9 = m1;
    sq_matrix<double> m10 = m2;
    sq_matrix<double> a11 = m9 - std::move(m10);
    if(!sq_matrix_eq(a11, sub_res, eps)){
        cout<<"Substraction operator error! (move_2)"<<endl;
        cout<<a11<<endl;
        cout<<sub_res<<endl;
    }

    sq_matrix<double> m11 = m1;
    sq_matrix<double> m12 = m2;
    sq_matrix<double> a12 = std::move(m11) - m12;
    if(!sq_matrix_eq(a12, sub_res, eps)){
        cout<<"Substraction operator error! (move1)"<<endl;
        cout<<a12<<endl;
        cout<<sub_res<<endl;
    }
    
    sq_matrix<double> m13 = m1;
    sq_matrix<double> m14 = m2;
    sq_matrix<double> a13 = m13 * std::move(m14);
    if(!sq_matrix_eq(a13, prod_res1, eps)){
        cout<<"Matrix product error! (move2)"<<endl;
        cout<<a13<<endl;
        cout<<prod_res1<<endl;
    }

    sq_matrix<double> m15 = m1;
    sq_matrix<double> m16 = m2;
    sq_matrix<double> a14 = std::move(m15) * m16;
    if(!sq_matrix_eq(a14, prod_res1, eps)){
        cout<<"Matrix product error! (move1)"<<endl;
        cout<<a14<<endl;
        cout<<prod_res1<<endl;
    }

    sq_matrix<double> m17 = m1;
    sq_matrix<double> m18 = m2;
    sq_matrix<double> a15 = std::move(m17) * std::move(m18);
    if(!sq_matrix_eq(a15, prod_res1, eps)){
        cout<<"Matrix product error! (move_both)"<<endl;
        cout<<a15<<endl;
        cout<<prod_res1<<endl;
    }

    return 0;

}


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    // Part A
    double U, th, D;
    double w=0.8, b=0.12, u=15.0, mew=3.4, d=0.5;
    double del_v=w*exp(b*u)+u*sin(th)*sin(th)+mew*log((D+1.0)/d)+sqrt(U*cos(th)+1.0);
    cout << fixed << setprecision(4) << del_v;
    
    // Part B
    int v_int = static_cast<int>(del_v);
    int f1 = static_cast<int>(round((del_v-v_int)*100));
    int f2 = static_cast<int>(round((del_v-v_int)*10000))%100;
    int R = 6570%89+10;
    double K = v_int*pow(10,6) + F1*pow(10,4) + F2*pow(10,2) + R;

    // Part C
    char c1 = 'A'+v_int%26;
    char c2 = 'Z'-(K - v_int*pow(10,6) + F1*pow(10,4) + F2*pow(10,2))%26;
    string c1c2 = {c1,c2};
    float del_v_1 = 
    return 0;
}
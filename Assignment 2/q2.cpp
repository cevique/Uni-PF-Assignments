#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    // Part A
    double U, th, D;
    cout << "Enter wind speed (U), terrain slope angle (th in radians), and vegetation fuel dryness index (D): ";
    cin >> U >> th >> D;
    double w=0.8, b=0.12, u=15.0, mew=3.4, d=0.5;
    double del_v = w*exp(b*U) + u*pow(sin(th), 2) + mew*log((D+1.0)/d) + sqrt(abs(U*cos(th)+1.0));
    cout << "1. Delta V: " << fixed << setprecision(4) << del_v << endl;
    
    // Part B
    int v_int = static_cast<int>(del_v);
    int F1 = static_cast<int>((del_v-v_int)*100);
    int F2 = static_cast<int>((del_v-v_int)*10000)%100;
    int R = 6570%89+10;
    int K = v_int*1000000 + F1*10000 + F2*100 + R;
    cout << "2. Telemetry key K: " << K << endl;

    // Part C
    int kR = K % 100;
    char c1 = 'A' + (K / 1000000) % 26;;
    char c2 = 'Z' - kR % 26;
    string c1c2 = {c1, c2};
    float v_float = static_cast<float>(K / 1000000) + static_cast<float>((K / 10000) % 100) / 100.0f + static_cast<float>((K / 100) % 100) / 10000.0f;
    double v_double = static_cast<double>(K / 1000000) + static_cast<double>((K / 10000) % 100) / 100.0 + static_cast<double>((K / 100) % 100) / 10000.0;
    cout << "3. Status Tag: " << c1c2 << endl;
    cout << "4. Precision Match Flag: " << boolalpha << (v_float == v_double) << endl;
    cout << "5. Threat Rating: " << kR + ((! (v_float == v_double)) * 25) + static_cast<int>(1.5 * v_double) << endl;
    return 0;
}
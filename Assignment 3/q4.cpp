#include <iostream>
#include <cmath>
using namespace std;

int fibonacci_sum(int f){
    int a=1, b=1;
    int s=0, t=0;
    for(int i=0; i<f; i++){
        s += a;
        t = b;
        b += a;
        a = t;
    }
    return s;
}

int main(){
    int n; cout << "N: "; cin >> n;
    int base; cout << "Base: "; cin >> base;
    int seed; cout << "Seed: "; cin >> seed;
    int seedrow = n-1;
    int seedcol = n-1;
    int value;
    
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int r = i-seedrow;
            int c = j-seedcol;
            if( i <= seedrow and j>=seedcol ){
                value = seed + fibonacci_sum( max( abs(r), abs(c) ) );
            }
            else if( i > seedrow and j <= seedcol ){
                value = seed - fibonacci_sum( max( abs(r), abs(c) ) );
            }
            else if( i <= seedrow and j < seedcol ){
                if( c >= r )
                    value = seed + fibonacci_sum(-r);
                else
                    value = seed + 2*fibonacci_sum(-r) - fibonacci_sum(-c);
            }
            else {
                if( c <= r )
                    value = seed - fibonacci_sum(r);
                else
                    value = seed + fibonacci_sum(c) - 2*fibonacci_sum(r);
            }
            value = (value%base + base) % base;
            if(value < 10) cout << value << ' ';
            else cout << (char)('A' + (value-10) ) << ' '; 
        }
        cout << '\n';
    }
    
    return 0;
}
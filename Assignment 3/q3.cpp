#include <iostream>
using namespace std;

int main(){

    int n; cout << "Enter n: "; cin >> n;
    
    if(n<=2 or n%2==0){
        cout << "Invalid input";
        return 1;
    }

    for(int i=0; i<n; i++){

        int left=0;
        int right=2*i;

        for(int sp=n-1-i; sp>0; sp--){
            cout << ' ';
        }

        for(int j=0; j<=right; j++){
            int dist = (right-j < j-left? right-j : j-left);
            dist %= 4;
            switch(dist){
                case 0: cout << '*'; break;
                case 1: cout << '.'; break;
                case 2: cout << 'O'; break;
                case 3: cout << '-';
            }
            
        }
        cout << '\n';

    }

    for(int i=n-1; i>=0; i--){
        
        int left=0;
        int right=2*i-2;

        for(int sp=0; sp<n-i; sp++){
            cout << ' ';
        }

        for(int j=0; j<=right; j++){
            int dist = (right-j < j-left? right-j : j-left);
            dist %= 4;
            switch(dist){
                case 0: cout << '*'; break;
                case 1: cout << '.'; break;
                case 2: cout << 'O'; break;
                case 3: cout << '-';
            }
            
        }
        cout << '\n';
    }

    return 0;
}
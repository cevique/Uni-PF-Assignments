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
        char c;

        for(int sp=n-1-i; sp>0; sp--){
            cout << ' ';
        }

        for(int j=0; j<=right; j++){
            int dist = (right-j < j-left? right-j : j-left);
            dist %= 4;
            if( ((n-1)/2) % 2 ){
                switch(dist){
                    case 0: c='O'; break;
                    case 1: c='-'; break;
                    case 2: c='*'; break;
                    case 3: c='.';
                }
            }
            else{
                switch(dist){
                    case 0: c = '*'; break;
                    case 1: c = '-'; break;
                    case 2: c = 'O'; break;
                    case 3: c = '.';
                }
            }
            cout << c;
            
        }
        cout << '\n';

    }

    for(int i=n-1; i>=0; i--){
        
        int left=0;
        int right=2*i-2;
        char c;

        for(int sp=0; sp<n-i; sp++){
            cout << ' ';
        }

        for(int j=0; j<=right; j++){
            int dist = (right-j < j-left? right-j : j-left);
            dist %= 4;
            if( ((n-1)/2) % 2 ){
                switch(dist){
                    case 0: c='O'; break;
                    case 1: c='-'; break;
                    case 2: c='*'; break;
                    case 3: c='.';
                }
            }
            else{
                switch(dist){
                    case 0: c = '*'; break;
                    case 1: c = '-'; break;
                    case 2: c = 'O'; break;
                    case 3: c = '.';
                }
            }
            cout << c;
            
        }
        cout << '\n';
    }

    return 0;
}
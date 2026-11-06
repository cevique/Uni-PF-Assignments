#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cout << "N: "; cin >> n;
    int base; cout << "Base: "; cin >> base;
    int seed; cout << "Seed: "; cin >> seed;
    int seedrow = n-1;
    int seedcol = n-1;
    int goldenRatio[n-1] = {};
    int fact=0, dact=1, t=0;
    int current = 0;
    for(int i=0; i<n-1; i++){
        t = dact;
        dact += fact;
        fact = t;
        goldenRatio[i] = current + fact%base;
        current = goldenRatio[i];
    }
    
    int grid[2*n-1][2*n-1] = {};
    grid[seedrow][seedcol] = seed;
    
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int dist = max( abs(i - seedrow), abs(j - seedcol) );
            if(dist == 0) continue;
            if(dist >= 1 && dist <= n-1){
                int gr = goldenRatio[dist-1];
                if( (i < seedrow) or ( i == seedrow and j >= seedcol)){
                    grid[i][j] = seed + gr;
                }
                else if( (i > seedrow) or ( i == seedrow and j <= seedcol) ){
                    grid[i][j] = seed - gr;
                }
            }
        }
    }
    
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            cout << ( base==16? 'A'+grid[i][j]%10 : grid[i][j] ) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter no. ";
    cin >> n;
    int left=1, top=1, right=n, bottom=n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int dist = i-left;
            if(j-top < dist) dist = j-top;
            if(right-i < dist) dist = right-i;
            if(bottom-j < dist) dist = bottom-j;
	        dist++;
            dist %= 10;
            cout << dist << ' ';
        }
        cout << '\n';
    }
    return 0;
}
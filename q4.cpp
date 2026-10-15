    #include<iostream>
    using namespace std;
    int main(){
        int n; cout<<"Enter size: "; cin>>n;
        if (n>0) {
            for (int r=0; r<n; r++) {
                for (int c = 0; c < n; ++c) {
                        int y = ((r<(n-1-r))? r : n-1-r);
                        int x = ((c<(n-1-c))? c : n-1-c);
                        int d = (x>y? x:y);
                        if (d % 2 == 0 or x == 0 or y == 0) {
                            cout << "* ";
                        }
                        else {
                            cout << ' ';
                        }
                    }
                    cout << '\n';
                }
            }
            else {
                cout << "Please enter a valid positive integer.\n";
            }
        return 0;
    }
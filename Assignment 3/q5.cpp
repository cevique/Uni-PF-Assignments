#include <iostream>
using namespace std;

int emptyCell = 0;
int wall = 1;
int start = 2;
int exitCell = 3;
int gold = 4;
int visited = 5;
int visitedGold = 6;
int visitedExitCell = 7;

int r0=0, r1=0, r2=0, r3=0, r4=0, r5=0, r6=0, r7=0, r8=0, r9=0;

int goldReachable = 0;
int exitCellReachable = 0;

int getRow(int r){
    switch(r){
        case 0: return r0;
        case 1: return r1;
        case 2: return r2;
        case 3: return r3;
        case 4: return r4;
        case 5: return r5;
        case 6: return r6;
        case 7: return r7;
        case 8: return r8;
        case 9: return r9;
    }
    return 0;
}

void setRow(int r, int value){
    switch(r){
        case 0: r0 = value; break;
        case 1: r1 = value; break;
        case 2: r2 = value; break;
        case 3: r3 = value; break;
        case 4: r4 = value; break;
        case 5: r5 = value; break;
        case 6: r6 = value; break;
        case 7: r7 = value; break;
        case 8: r8 = value; break;
        case 9: r9 = value;
    }
}

int getCell(int r, int c){
    int place = 1;
    for(int i=0; i<c; i++){
        place *= 8;
    }
    return getRow(r) / place % 8;
}

void setCell(int r, int c, int value){
    int row = getRow(r);
    int place = 1;
    int oldValue = 0;
    for(int i=0; i<c; i++){
        place *= 8;
    }
    oldValue = row / place % 8;
    row = row - oldValue*place  + value*place;
    setRow(r, row);
}

int visitCell(int r, int c){
    int cell = getCell(r, c);
    if(cell == emptyCell){
        setCell(r, c, visited);
        return 1;
    }
    if(cell == gold){
        setCell(r, c, visitedGold);
        goldReachable++;
        return 1;
    }
    if(cell == exitCell){
        setCell(r, c, visitedExitCell);
        exitCellReachable++;
        return 1;
    }
    return 0;
}

int main(){
    int n; cin >> n;
    if(n < 2 or n > 10){
        cout << "Invalid input.";
        return 0;
    }
    int startR, startC;
    int state;
    char ch;

    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            cin >> ch;
            if(ch == 'S'){
                state = start;
                startR = r;
                startC = c;
            }
            else if(ch == '*'){
                state = wall;
            }
            else if(ch == '.'){
                state = emptyCell;
            }
            else if(ch == 'G'){
                state = gold;
            }
            else if(ch == 'E'){
                state = exitCell;
            }
            else{
                cout << "\nInvalid choice.";
                return 0;
            }
            setCell(r, c, state);
        }
    }

    setCell(startR, startC, visited);

    int changed;

    do{
        changed = 0;

        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                state = getCell(r,c);
                if(state == visited or state == visitedGold or state == visitedExitCell){
                    if(r > 0) changed += visitCell(r-1, c);
                    if(r < n-1) changed += visitCell(r+1, c);
                    if(c > 0) changed += visitCell(r, c-1);
                    if(c < n-1) changed += visitCell(r,c+1);
                }
            }
        }

    } while(changed > 0);

    if(exitCellReachable) cout << "Solvable: YES" << '\n';
    else cout << "Solvable: NO" << '\n';

    cout << "Gold reachable: " << goldReachable << '\n';    

    return 0;
}
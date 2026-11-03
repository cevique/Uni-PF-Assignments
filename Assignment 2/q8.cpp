#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(NULL));

    int pmX = rand() % 20, pmY = rand() % 10;
    int clX = rand() % 20, clY = rand() % 10;
    int ikX = rand() % 20, ikY = rand() % 10;
    int pkX = rand() % 20, pkY = rand() % 10;
    int bkSpawn = rand() % 40;
    int bkPhase = (bkSpawn < 20) ? 0 : 1;
    int bkX = (bkSpawn < 20) ? bkSpawn : (bkSpawn - 20);
    int bkY = (bkPhase == 0) ? 2 : 7;

    int gmState = 0;

    while (gmState == 0) {
        for (int i = 0; i < 40; i++)
            cout << '\n';

        cout << "PAC-A-MAN!\n";
        cout << "Controls: W A S D + Enter" << endl << endl;

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 20; x++) {
                char ch = '*';
                ch = (x == pmX and y == pmY) ? '@' : ch;
                ch = (x == clX and y == clY) ? 'C' : ch;
                ch = (x == ikX and y == ikY) ? 'I' : ch;
                ch = (x == pkX and y == pkY) ? 'P' : ch;
                ch = (x == bkX and y == bkY) ? 'B' : ch;
                cout << ch << " ";
            }
            cout << endl;
        }

        char usrCmd;
        cout << "\nTurn: ";
        cin >> usrCmd;

        int prevX = pmX;
        int prevY = pmY;

        switch (usrCmd) {
            case 'W':
            case 'w':
                pmY--;
                break;
            case 'S':
            case 's': 
                pmY++; 
                break;
            case 'A':
            case 'a':
                pmX--;
                break;
            case 'D':
            case 'd':
                pmX++;
                break;
            default:
                break;
        }

        pmX = (pmX>0 ? (pmX > 19 ? 19 : pmX) : 0);
        pmY = (pmY>0? (pmY > 9 ? 9 : pmY) : 0);

        clX += pmX - prevX;
        clY += pmY - prevY;
        clX = (clX>0 ? (clX > 19 ? 19 : clX) : 0);
        clY = (clY>0 ? (clY > 9 ? 9 : clY): 0);
        gmState = (pmX == clX and pmY == clY) ? 1 : gmState;

        switch(gmState) {
            case 0:
            int distC = (clX - pmX) * (clX - pmX) + (clY - pmY) * (clY - pmY);
            int distI = (ikX - pmX) * (ikX - pmX) + (ikY - pmY) * (ikY - pmY);
            int distP = (pkX - pmX) * (pkX - pmX) + (pkY - pmY) * (pkY - pmY);
            int distB = (bkX - pmX) * (bkX - pmX) + (bkY - pmY) * (bkY - pmY);

            int inkyIsClosest = (distI <= distC and distI <= distP and distI <= distB) ? 1 : 0;

            int freeUp = (ikY > 0 and !(ikX == clX and ikY - 1 == clY) and !(ikX == pkX and ikY - 1 == pkY) and !(ikX == bkX and ikY - 1 == bkY)) ? 1 : 0;
            int freeRt = (ikX < 19 and !(ikX + 1 == clX and ikY == clY) and !(ikX + 1 == pkX and ikY == pkY) and !(ikX + 1 == bkX and ikY == bkY)) ? 1 : 0;
            int freeDn = (ikY < 9 and !(ikX == clX and ikY + 1 == clY) and !(ikX == pkX and ikY + 1 == pkY) and !(ikX == bkX and ikY + 1 == bkY)) ? 1 : 0;
            int freeLf = (ikX > 0 and !(ikX - 1 == clX and ikY == clY) and !(ikX - 1 == pkX and ikY == pkY) and !(ikX - 1 == bkX and ikY == bkY)) ? 1 : 0;

            int newIkX = inkyIsClosest ? (freeUp ? ikX : (freeRt ? ikX + 1 : (freeDn ? ikX : (freeLf ? ikX - 1 : ikX)))) : ikX;
            int newIkY = inkyIsClosest ? (freeUp ? ikY - 1 : (freeRt ? ikY : (freeDn ? ikY + 1 : (freeLf ? ikY : ikY)))) : ikY;

            ikX = newIkX;
            ikY = newIkY;

            gmState = (pmX == ikX and pmY == ikY) ? 2 : gmState;

            break;
        }

        switch(gmState) {
            case 0:
            int dx = pmX - pkX;
            int dy = pmY - pkY;
            int adx = (dx < 0) ? -dx : dx;
            int ady = (dy < 0) ? -dy : dy;
            int stepX = (dx > 0) ? 1 : (dx < 0 ? -1 : 0);
            int stepY = (dy > 0) ? 1 : (dy < 0 ? -1 : 0);

            int cmp = (adx > ady) ? 0 : (ady > adx ? 1 : 2);

            int newPkX = pkX + ((cmp == 0) ? stepX : (cmp == 2 ? stepX : 0));
            int newPkY = pkY + ((cmp == 1) ? stepY : (cmp == 2 ? stepY : 0));

            newPkX = (newPkX < 0) ? 0 : (newPkX > 19 ? 19 : newPkX);
            newPkY = (newPkY < 0) ? 0 : (newPkY > 9 ? 9 : newPkY);

            pkX = newPkX;
            pkY = newPkY;

            gmState = (pmX == pkX and pmY == pkY) ? 2 : gmState;
            
            break;
        }

        switch(gmState) {
            case 0:
            int step = (bkPhase == 0) ? 1 : -1;
            int nextX = bkX + step;

            int hitRight = (bkPhase == 0 and nextX > 19) ? 1 : 0;
            int hitLeft = (bkPhase == 1 and nextX < 0) ? 1 : 0;

            switch (hitRight * 2 + hitLeft) {
                case 2:
                    bkPhase = 1;
                    nextX = 19;
                    bkY = 7;
                    break;
                case 1:
                    bkPhase = 0;
                    nextX = 0;
                    bkY = 2;
                    break;
                default:
                    break;
            }

            bkX = nextX;

            gmState = (pmX == bkX and pmY == bkY) ? 2 : gmState;
            
            break;
        }
    }

    for (int i = 0; i < 40; i++) cout << '\n';

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 20; x++) {
            char ch = '*';
            ch = (x == clX and y == clY) ? 'C' : ch;
            ch = (x == ikX and y == ikY) ? 'I' : ch;
            ch = (x == pkX and y == pkY) ? 'P' : ch;
            ch = (x == bkX and y == bkY) ? 'B' : ch;
            ch = (x == pmX and y == pmY) ? '@' : ch;
            cout << ch << " ";
        }
        cout << endl;
    }

    switch (gmState) {
        case 1:
            cout << "\nSiren activated, you win!\n";
            break;
        case 2:
            cout << "\nGame over.\n";
            break;
    }

    return 0;
}
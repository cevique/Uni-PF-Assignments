#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(NULL));

    // Random starting positions
    int Px = rand() % 20, Py = rand() % 10; // Pacman
    int Cx = rand() % 20, Cy = rand() % 10; // Clyde
    int Ix = rand() % 20, Iy = rand() % 10; //  Inky
    int Pix = rand() % 20, Piy = rand() % 10;   //  Pinky

    // Blinky: starts at top line (y=2), moving right
    int Bx = 0, By = 2;
    int B_state = 0; // 0: top moving right, 1: bottom moving left

    int game_state = 0; // 0 = Playing, 1 = Win, 2 = Loss

    while (game_state == 0) {

        for (int i = 0; i < 40; i++) cout << '\n';

        cout << "PAC-A-MAN!\n";
        cout << "Controls: W A S D + Enter\n\n";

        // Draw board
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 20; x++) {
                char cell = '*';
                cell = (x == Cx && y == Cy) ? 'C' : cell;
                cell = (x == Ix && y == Iy) ? 'I' : cell;
                cell = (x == Pix && y == Piy) ? 'P' : cell;
                cell = (x == Bx && y == By) ? 'B' : cell;
                cell = (x == Px && y == Py) ? '@' : cell;
                cout << cell << ' ';
            }
            cout << '\n';
        }

        // Get player input
        char input;
        cout << "\nMove: ";
        cin >> input;

        int old_Px = Px, old_Py = Py;

        // Pac-Man movement
        switch (input) {
        case 'W':
        case 'w':
            Py--;
            break;
        case 'S':
        case 's': 
            Py++;
            break;
        case 'A':
        case 'a':
            Px--; 
            break;
        case 'D':
        case 'd':
            Px++;
            break;
        default:
            break;
        }

        // Boundary constraints
        Px = (Px < 0) ? 0 : ((Px > 19) ? 19 : Px);
        Py = (Py < 0) ? 0 : ((Py > 9) ? 9 : Py);

        // CLYDE LOGIC
        int pac_dx = Px - old_Px;
        int pac_dy = Py - old_Py;
        Cx = Cx + pac_dx;
        Cy = Cy + pac_dy;
        Cx = (Cx < 0) ? 0 : ((Cx > 19) ? 19 : Cx);
        Cy = (Cy < 0) ? 0 : ((Cy > 9) ? 9 : Cy);

        if (Px == Cx && Py == Cy) {
            game_state = 1;
        }

        // INKY LOGIC
        if (game_state == 0) {
            int dC = (int)(Cx - Px)*(Cx - Px) + (Cy - Py)*(Cy - Py);
            int dI = (int)(Ix - Px)*(Ix - Px) + (Iy - Py)*(Iy - Py);
            int dP = (int)(Pix - Px)*(Pix - Px) + (Piy - Py)*(Piy - Py);
            int dB = (int)(Bx - Px)*(Bx - Px) + (By - Py)*(By - Py);

            bool inky_closest = (dI <= dC) && (dI <= dP) && (dI <= dB);

            if (inky_closest) {
                // Find free spaces clockwise from top
                bool free_top = (Iy - 1 >= 0) && !(Px == Cx && Iy - 1 == Cy) 
                    && !(Px == Pix && Iy - 1 == Piy) && !(Px == Bx && Iy - 1 == By);
                bool free_rgt = (Ix + 1 <= 19) && !(Ix + 1 == Cx && Iy == Cy) 
                    && !(Ix + 1 == Pix && Iy == Piy) && !(Ix + 1 == Bx && Iy == By);
                bool free_bot = (Iy + 1 <= 9) && !(Ix == Cx && Iy + 1 == Cy) 
                    && !(Ix == Pix && Iy + 1 == Piy) && !(Ix == Bx && Iy + 1 == By);
                bool free_lft = (Ix - 1 >= 0) && !(Ix - 1 == Cx && Iy == Cy) 
                    && !(Ix - 1 == Pix && Iy == Piy) && !(Ix - 1 == Bx && Iy == By);

                if (free_top) { Iy--; }
                else if (free_rgt) { Ix++; }
                else if (free_bot) { Iy++; }
                else if (free_lft) { Ix--; }
            }

            if (Px == Ix && Py == Iy) {
                game_state = 2; // Loss
            }
        }

        // ===== PINKY LOGIC =====
        if (game_state == 0) {
            int pinky_dx = Px - Pix;
            int pinky_dy = Py - Piy;
            int abs_pdx = (pinky_dx < 0) ? -pinky_dx : pinky_dx;
            int abs_pdy = (pinky_dy < 0) ? -pinky_dy : pinky_dy;

            if (abs_pdx > abs_pdy) {
                // Move horizontally
                Pix += (pinky_dx > 0) ? 1 : -1;
            } else if (abs_pdy > abs_pdx) {
                // Move vertically
                Piy += (pinky_dy > 0) ? 1 : -1;
            } else {
                // Diagonal on tie
                Pix += (pinky_dx > 0) ? 1 : -1;
                Piy += (pinky_dy > 0) ? 1 : -1;
            }

            // Boundary constraints
            Pix = (Pix < 0) ? 0 : ((Pix > 19) ? 19 : Pix);
            Piy = (Piy < 0) ? 0 : ((Piy > 9) ? 9 : Piy);

            if (Px == Pix && Py == Piy) {
                game_state = 2; // Loss
            }
        }

        // BLINKY LOGIC
        if (game_state == 0) {
            int new_Bx = Bx + ((B_state == 0) ? 1 : -1);

            if (B_state == 0) {
                // Top line (y=2), moving right
                if (new_Bx > 19) {
                    B_state = 1;
                    new_Bx = 19;
                    By = 7; // Switch to bottom line (height 3 from bottom)
                }
            } else {
                // Bottom line (y=7), moving left
                if (new_Bx < 0) {
                    B_state = 0;
                    new_Bx = 0;
                    By = 2; // Switch to top line
                }
            }

            Bx = new_Bx;

            if (Px == Bx && Py == By) {
                game_state = 2; // Loss
            }
        }
    }

    // Clear screen and display final board
    for (int i = 0; i < 40; i++) cout << '\n';

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 20; x++) {
            char cell = '*';
            cell = (x == Cx && y == Cy) ? 'C' : cell;
            cell = (x == Ix && y == Iy) ? 'I' : cell;
            cell = (x == Pix && y == Piy) ? 'P' : cell;
            cell = (x == Bx && y == By) ? 'B' : cell;
            cell = (x == Px && y == Py) ? '@' : cell;
            cout << cell << ' ';
        }
        cout << '\n';
    }

    if (game_state == 1) {
        cout << "\nSiren activated, you win!\n";
    } else {
        cout << "\nGame over gg.\n";
    }

    return 0;
}

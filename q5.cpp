#include <iostream>

using namespace std;
int main(){
    
    char userChoice;
    cout << "Enter choice (A/B): "; cin >> userChoice;

    switch (userChoice) {
    case 'A': {
        int houseWidth, houseHeight, doorWidth, doorHeight, atticHeight, chimneyCount, walkwayHeight;
        bool isInputValid;

        // User Input & Validation
        while (true) {
            cout << "Width of house: ";
            while (!(cin >> houseWidth) || houseWidth < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(10000, '\n');
            }
            cout << "Height of house: ";
            while (!(cin >> houseHeight) || houseHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(10000, '\n');
            }
            cout << "Width of door: ";
            while (!(cin >> doorWidth) || doorWidth < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(10000, '\n');
            }
            cout << "Height of door: ";
            while (!(cin >> doorHeight) || doorHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(10000, '\n');
            }
            cout << "Height of attic (base to roof): ";
            while (!(cin >> atticHeight) || atticHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(10000, '\n');
            }
            cout << "Number of chimneys: ";
            while (!(cin >> chimneyCount) || chimneyCount < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(10000, '\n');
            }
            cout << "Height of walkway: ";
            while (!(cin >> walkwayHeight) || walkwayHeight < 0) {
                cout << "Invalid input. Enter a non-negative whole number: ";
                cin.clear(); cin.ignore(10000, '\n');
            }

            isInputValid = true;
            if (atticHeight < 1)
                cout << "Error: attic height must be at least 1.\n"; isInputValid = false;
        
            else if (walkwayHeight < 1)
                cout << "Error: walkway height must be at least 1.\n"; isInputValid = false;

            else if (houseWidth % 2 != 0 || doorWidth % 2 != 0)
                cout << "Error: house width and door width must both be even.\n"; isInputValid = false;

            else if (doorWidth < 4)
                cout << "Error: door width must be at least 4.\n"; isInputValid = false;

            else if (doorHeight < 3)
                cout << "Error: door height must be at least 3.\n"; isInputValid = false;

            else if (houseWidth < doorWidth + 20)
                cout << "Error: house too narrow (width must be at least door width + 20).\n"; isInputValid = false;

            else if (houseWidth < 2 * atticHeight + 2)
                cout << "Error: attic is too wide for the house width.\n"; isInputValid = false;

            else if (houseHeight < atticHeight + walkwayHeight + (doorHeight + 1 > 6 ? doorHeight + 1 : 6))
                cout << "Error: house height too small for attic, door and walkway.\n"; isInputValid = false;

            else if (walkwayHeight > (houseWidth - doorWidth) / 2)
                cout << "Error: walkway too tall for this house width.\n"; isInputValid = false;

            else if (chimneyCount > 0 && atticHeight < 3)
                cout << "Error: attic must be at least 3 tall to hold chimneys.\n"; isInputValid = false;

            else if (chimneyCount > 0 && chimneyCount > 2 * ((houseWidth / 2 - atticHeight - 1) / 6))
                cout << "Error: too many chimneys for this house width.\n"; isInputValid = false;


            if (isInputValid) break;
            
            cout << "Please re-enter all inputs.\n\n";
        }

        // Structural Dimensions Calculation
        int centerColumn = houseWidth / 2;
        int doorLeftColumn = (houseWidth - doorWidth) / 2;
        int doorBottomRow = houseHeight - walkwayHeight - 1;
        int doorTopRow = doorBottomRow - doorHeight + 1;
        int roofWingWidth = centerColumn - atticHeight - 1;
        int leftSideChimneys = (chimneyCount + 1) / 2;
        int rightSideChimneys = chimneyCount / 2;

        cout << "\n";

        // House ASCII Rendering
        for (int row = 0; row < houseHeight; row++) {
            for (int col = 0; col < houseWidth; col++) {
                char drawChar = ' ';

                if (row >= houseHeight - walkwayHeight) {
                    // Walkway Section
                    int walkRowOffset = row - (houseHeight - walkwayHeight);
                    if (col == doorLeftColumn - 1 - walkRowOffset) drawChar = '/';
                    else if (col == doorLeftColumn + doorWidth + walkRowOffset) drawChar = '\\';
                    else if (walkRowOffset == walkwayHeight - 1 && col >= doorLeftColumn - walkRowOffset && col < doorLeftColumn + doorWidth + walkRowOffset) drawChar = '_';
                }
                else if (row < atticHeight) {
                    // Attic & Chimneys Section
                    if (col == centerColumn - 1 - row) drawChar = '/';
                    else if (col == centerColumn + row) drawChar = '\\';
                    else if (atticHeight >= 4 && row == atticHeight - 2 && col == centerColumn - 1) drawChar = '[';
                    else if (atticHeight >= 4 && row == atticHeight - 2 && col == centerColumn) drawChar = ']';
                    else if (chimneyCount > 0 && row >= atticHeight - 3) {
                        int chimneyOffset = -1;
                        for (int side = 0; side < 2; side++) {
                            int segmentStart = (side == 0) ? 1 : centerColumn + atticHeight;
                            int chimneyCountOnSide = (side == 0) ? leftSideChimneys : rightSideChimneys;

                            if (chimneyCountOnSide > 0 && col >= segmentStart && col < segmentStart + roofWingWidth) {
                                int slotSize = roofWingWidth / chimneyCountOnSide;
                                int chimneyIndex = (col - segmentStart) / slotSize;
                                if (chimneyIndex < chimneyCountOnSide) {
                                    int offsetInChimney = col - (segmentStart + chimneyIndex * slotSize + (slotSize - 5) / 2);
                                    if (offsetInChimney >= 0 && offsetInChimney <= 4) chimneyOffset = offsetInChimney;
                                }
                            }
                        }

                        if (chimneyOffset >= 0) {
                            int chimneyRowOffset = row - (atticHeight - 3);
                            if (chimneyRowOffset == 0) { if (chimneyOffset == 1 || chimneyOffset == 3) drawChar = ')'; }
                            else if (chimneyRowOffset == 1) drawChar = '=';
                            else {
                                if (chimneyOffset == 1 || chimneyOffset == 3) drawChar = '|';
                                else if (chimneyOffset == 2) drawChar = '_';
                            }
                        }
                    }
                }
                else if (row == atticHeight) {
                    // Roof Baseline
                    if (col >= 1 && col <= houseWidth - 2) drawChar = '_';
                }
                else if (col == 0 || col == houseWidth - 1) {
                    // Outer Walls
                    drawChar = '|';
                }
                else if (col >= doorLeftColumn && col <= doorLeftColumn + doorWidth - 1) {
                    // Door Section
                    if (row == doorTopRow) {
                        if (col > doorLeftColumn && col < doorLeftColumn + doorWidth - 1) drawChar = '_';
                    }
                    else if (row > doorTopRow) {
                        if (col == doorLeftColumn || col == doorLeftColumn + doorWidth - 1) drawChar = '|';
                        else if (row == doorTopRow + doorHeight / 2 && col == doorLeftColumn + doorWidth - 2) drawChar = 'o';
                        else if (row == doorBottomRow) drawChar = '_';
                    }
                }
                else {
                    // Windows Section
                    if (row >= doorBottomRow - 4 && row <= doorBottomRow - 1) {
                        int regionStart = (col < doorLeftColumn) ? 1 : doorLeftColumn + doorWidth;
                        int regionWidth = doorLeftColumn - 1;
                        int windowsInRegion = regionWidth / 9;
                        int relativeCol = col - regionStart - (regionWidth - windowsInRegion * 9) / 2;

                        if (relativeCol >= 0 && relativeCol / 9 < windowsInRegion) {
                            int windowColOffset = relativeCol % 9 - 1;
                            int windowRowOffset = row - (doorBottomRow - 4);

                            if (windowColOffset >= 0 && windowColOffset <= 6) {
                                if (windowRowOffset == 0) { if (windowColOffset >= 1 && windowColOffset <= 5) drawChar = '_'; }
                                else if (windowRowOffset == 1) { if (windowColOffset == 0 || windowColOffset == 3 || windowColOffset == 6) drawChar = '|'; }
                                else if (windowRowOffset == 2) {
                                    if (windowColOffset == 0 || windowColOffset == 6) drawChar = '|';
                                    else if (windowColOffset == 3) drawChar = '+';
                                    else drawChar = '-';
                                }
                                else {
                                    if (windowColOffset == 0 || windowColOffset == 3 || windowColOffset == 6) drawChar = '|';
                                    else drawChar = '_';
                                }
                            }
                        }
                    }
                    if (row == doorBottomRow && drawChar == ' ') drawChar = '_';
                }
                cout << drawChar;
            }
            cout << "\n";
        }
        break;
    }
    case 'B': {
        int inputCode;
        cout << "Enter a 4 digit input : "; cin >> inputCode;

        // Extract Digits
        int firstDigit  = inputCode / 1000;
        int secondDigit = (inputCode / 100) % 10;
        int thirdDigit  = (inputCode / 10) % 10;
        int fourthDigit = inputCode % 10;

        // Train Car ASCII Rendering
        for (int row = 1; row <= 6; ++row) {
            int currentDigit = 0;

            for (int cartPosition = 1; cartPosition <= 4; ++cartPosition) {
                if (cartPosition == 1)      currentDigit = firstDigit;
                else if (cartPosition == 2) currentDigit = secondDigit;
                else if (cartPosition == 3) currentDigit = thirdDigit;
                else if (cartPosition == 4) currentDigit = fourthDigit;

                // Row 1
                if (row == 1) {
                    if (currentDigit == 1)      cout << "   o O                          ";
                    else if (currentDigit == 2) cout << "                     ";
                    else if (currentDigit == 3) cout << "                      ";
                    else if (currentDigit == 4) cout << "                          ";
                }
                // Row 2
                else if (row == 2) {
                    if (currentDigit == 1)      cout << "   ___[ ]___  _________________  ";
                    else if (currentDigit == 2) cout << "  _________________  ";
                    else if (currentDigit == 3) cout << "|==================|  ";
                    else if (currentDigit == 4) cout << "       __[___]__          ";
                }
                // Row 3
                else if (row == 3) {
                    if (currentDigit == 1)      cout << " |_________|_| [ ]       [ ] |  ";
                    else if (currentDigit == 2) cout << " | []  []  []  []  | ";
                    else if (currentDigit == 3) cout << "|    |   []   |    |  ";
                    else if (currentDigit == 4) cout << " \'-===================-\'  ";
                }
                // Row 4
                else if (row == 4) {
                    if (currentDigit == 1)      cout << " |___( )___|_|_______________|  ";
                    else if (currentDigit == 2) cout << " | []  []  []  []  | ";
                    else if (currentDigit == 3) cout << "|    |   ||   |    |  ";
                    else if (currentDigit == 4) cout << "(    ~~~~~~~~~~~~~~~    ) ";
                }
                // Row 5
                else if (row == 5) {
                    if (currentDigit == 1)      cout << "<============================]--";
                    else if (currentDigit == 2) cout << "-|_________________|-";
                    else if (currentDigit == 3) cout << "|____|___||___|____|--";
                    else if (currentDigit == 4) cout << " \'-====================-\',";
                }
                // Row 6
                else if (row == 6) {
                    if (currentDigit == 1)      cout << " (O)     (O)  (O)         (O)   ";
                    else if (currentDigit == 2) cout << "   (O)         (O)   ";
                    else if (currentDigit == 3) cout << "    (O)      (O)      ";
                    else if (currentDigit == 4) cout << "    (O)             (0)   ";
                }
            }
            cout << "\n";
        }
        break;
    }
    default: cout << "Please choice A or B next time.\n"; break;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    
    int size;
    cout << "Enter size (e.g. 16): ";
    cin >> size;

    int halfHeight = 3 * size / 2 + 1;
    int halfWidth = 7 * size / 4;
    int tip = 2 * halfHeight - 1;
    int figureWidth = 2 * tip + 1;
    int termWidth = 120;
    int leftPad = (termWidth > figureWidth) ? (termWidth - figureWidth) / 2 : 0;

    for (int row = -halfHeight; row <= halfHeight; row++)
    {
        for (int p = 0; p < leftPad; p++)
            cout << ' ';

        int distanceY = (row < 0) ? -row : row;
        int distanceFromTip = halfHeight - distanceY;
        int outerEdge = 2 * distanceFromTip;

        if (outerEdge > halfWidth)
            outerEdge = halfWidth;

        int innerEdge = 2 * distanceFromTip - 4;

        if (innerEdge > halfWidth - 2)
            innerEdge = halfWidth - 2;

        int scaledY = row * 16 / size;
        int vertical = scaledY * 19;

        for (int col = -tip; col <= tip; col++)
        {
            int distanceX = (col < 0) ? -col : col;
            int scaledX = col * 16 / size;
            int absScaledX = (scaledX < 0) ? -scaledX : scaledX;
            int horizontal = absScaledX * 10;
            int distanceSquared = horizontal * horizontal
                                + vertical * vertical;

            bool face = false;

            // FACE
            if (scaledY >= -8 && scaledY <= 8
                && distanceSquared <= 175 * 175
                && distanceSquared > 134 * 134)
                face = true;

            // Eyes - Rectangular, scaled with input
            // Right eye: scaledX in [4, 8], scaledY in [-5, -1]
            // Left eye: scaledX in [-8, -4], scaledY in [-5, -1]
            if (absScaledX >= 4 && absScaledX <= 8 && scaledY >= -5 && scaledY <= -1)
                face = true;

            // Sad mouth
            int mouthOuter = horizontal * horizontal * 4225
                           + (vertical - 95) * (vertical - 95) * 9025;

            int mouthInner = horizontal * horizontal * 1225
                           + (vertical - 95) * (vertical - 95) * 3600;

            if (vertical >= 20 && vertical <= 95
                && mouthOuter <= 9025 * 4225
                && mouthInner > 3600 * 1225)
                face = true;

            // Blood drops
            if (absScaledX == 23 && scaledY >= 1 && scaledY <= 3)
                face = true;

            if (absScaledX == 17 && scaledY >= 5 && scaledY <= 8)
                face = true;

            if (absScaledX == 12 && scaledY >= 8 && scaledY <= 10)
                face = true;

            if (absScaledX == 6 && scaledY >= 9 && scaledY <= 10)
                face = true;

            if (absScaledX <= 1 && scaledY >= 9 && scaledY <= 10)
                face = true;

            if (face)
                cout << "\033[91m#\033[0m";  // Bright red face
            else if (distanceX >= innerEdge && distanceX <= outerEdge)
                cout << "\033[37mX\033[0m";  // White border
            else if (distanceX >= 2 * distanceFromTip - 7
                     && distanceX <= 2 * distanceFromTip - 3)
                cout << "\033[36m+\033[0m";  // Cyan diagonal lines
            else if (distanceY == 0
                     && distanceX > halfWidth && distanceX <= tip)
                cout << "\033[36m+\033[0m";  // Cyan middle line
            else if (distanceX < innerEdge)
            {
                if ((distanceFromTip + distanceX) % 2 == 1)
                    cout << "\033[90m.\033[0m";  // Dark gray dotted interior
                else
                    cout << " ";
            }
            else
                cout << " ";
        }

        cout << '\n';
    }

    return 0;
}
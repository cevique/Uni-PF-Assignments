#include <iostream>
using namespace std;

void initBoard(char board[6][7]) {
    for (int row = 0; row < 6; ++row)
        for (int col = 0; col < 7; ++col)
            board[row][col] = '.';
}

void printBoard(char board[6][7]) {
    cout << "\n";

    for (int row = 0; row < 6; ++row) {
        cout << "\033[1;34m|\033[0m ";
        for (int col = 0; col < 7; ++col) {
            char currentCell = board[row][col];
            (currentCell == 'X') ? cout << "\033[1;31mX\033[0m " :
            ((currentCell == 'O') ? cout << "\033[1;33mO\033[0m " :
            cout << "\033[90m.\033[0m ");
        }
        cout << "\033[1;34m|\033[0m\n";
    }

    cout << "\033[1;34m+---------------+\033[0m\n";
    cout << "  ";

    for (int col = 0; col < 7; ++col)
        cout << col << " ";
    cout << '\n' << '\n';
}

int updateColumn(char board[6][7], int column, char mark) {

    if (column < 0 or column > 6)
        return -1;
 
    bool isRemoval = (mark == '.');

    for (int row = (isRemoval ? 0 : 5); (isRemoval ? row < 6 : row >= 0); (isRemoval ? ++row : --row)) {
        if ((isRemoval and board[row][column] != '.') or (!isRemoval and board[row][column] == '.')) {
            board[row][column] = mark;
            return row;
        }
    }

    return -1;
}

bool isBoardFull(char board[6][7]) {
    for (int col = 0; col < 7; ++col) {
        if (board[0][col] == '.')
            return false;
    }

    return true;
}

bool checkWin(char board[6][7], char player) {

    for (int row = 0; row < 6; ++row)
        for (int col = 0; col < 4; ++col)
            if (board[row][col] == player and board[row][col+1] == player and board[row][col+2] == player and board[row][col+3] == player)
                return true;

    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 7; ++col)
            if (board[row][col] == player and board[row+1][col] == player and board[row+2][col] == player and board[row+3][col] == player)
                return true;

    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 4; ++col)
            if (board[row][col] == player and board[row+1][col+1] == player and board[row+2][col+2] == player and board[row+3][col+3] == player)
                return true;

    for (int row = 3; row < 6; ++row)
        for (int col = 0; col < 4; ++col)
            if (board[row][col] == player and board[row-1][col+1] == player and board[row-2][col+2] == player and board[row-3][col+3] == player)
                return true;

    return false;
}

int evaluateWindow(int computerCount, int player_count, int empty_count) {
    return (computerCount == 3 and empty_count == 1) ? 5 : ((computerCount == 2 and empty_count == 2) ? 2 : ((player_count == 3 and empty_count == 1) ? -4 : 0));
}


int evaluateBoard(char board[6][7]) {
    int total_score = 0;

    int computer_count, player_count, empty_count;
    char cell;

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row][col + k];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 7; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row + k][col];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row + k][col + k];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 3; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            computer_count = 0;
            player_count = 0;
            empty_count = 0;

            for (int k = 0; k < 4; ++k) {
                cell = board[row - k][col + k];

                if (cell == 'O')
                    computer_count++;
                else if (cell == 'X')
                    player_count++;
                else
                    empty_count++;
            }

            total_score += evaluateWindow(
                computer_count, player_count, empty_count
            );
        }
    }

    for (int row = 0; row < 6; ++row) {
        if (board[row][3] == 'O')
            total_score += 3;
    }
    return total_score;
}


int minimax(char board[6][7], int ply, int L, int U) {
    if (ply > 3)
        return evaluateBoard(board);

    int column_order[7] = {3, 2, 4, 1, 5, 0, 6};

    for (int i = 0; i < 7; ++i) {
        int column = column_order[i];
        int row = updateColumn(board, column, (ply % 2 != 0) ? 'O' : 'X');

        if (row == -1)
            continue;

        int score = 0;

        if (ply == 1 and checkWin(board, 'O'))
            score = 100002;
        else if (ply == 2 and checkWin(board, 'X'))
            score = -100001;
        else if (ply == 3 and checkWin(board, 'O'))
            score = 100000;
        else if (isBoardFull(board))
            score = 0;
        else if (ply == 3)
            score = evaluateBoard(board);
        else
            score = minimax(board, ply + 1, L, U);

        updateColumn(board, column, '.');

        if (ply == 1 or ply == 3) {
            if (score > L)
                L = score;
        } else {
            if (score < U)
                U = score;
        }

        if (L >= U)
            break;
    }

    return (ply == 1 or ply == 3) ? L : U;
}

int getComputerMove(char board[6][7]) {
    int best_column = -1;
    int best_score = -2000000;
    int L = -1000000;
    int U = 1000000;
    int column_order[7] = {3, 2, 4, 1, 5, 0, 6};

    for (int i = 0; i < 7; ++i) {
        int column = column_order[i];
        int row = updateColumn(board, column, 'O');

        if (row == -1)
            continue;

        int score = checkWin(board, 'O') ? 100002 : minimax(board, 2, L, U);

        updateColumn(board, column, '.');

        if (best_column == -1 or score > best_score) {
            best_score = score;
            best_column = column;
        }

        if (score > L)
            L = score;

        if (L >= U)
            break;
    }

    return best_column;
}

int main() {

    char board[6][7];
    initBoard(board);
    printBoard(board);

    while (true) {
  
        int user_column = -1;

        while (true) {
            cout << "\033[1;32mYour turn (Player X) - Enter column (0-6): \033[0m";
            cin >> user_column;

            if (cin.fail() or user_column < 0 or user_column > 6) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[1;31mInvalid input! Enter a valid column number between 0 and 6.\033[0m\n";
                continue;
            }

            int row = updateColumn(board, user_column, 'X');
            if (row == -1) {
                cout << "\033[1;31mColumn is full! Choose another column.\033[0m\n";
                continue;
            }

            break;
        }

        printBoard(board);

        if (checkWin(board, 'X')) {
            cout << "\033[1;32m🎉 Congratulations! You (X) won the game! 👑🏆🗿 Bro actually cooked the AI!\033[0m\n";
            break;
        }

        if (isBoardFull(board)) {
            cout << "\033[1;33m🤝 It's a draw! Board is full. 🥱Absolute Stalemate\033[0m\n";
            break;
        }

        cout << "\033[1;35mComputer (O) is calculating best move (3-ply search)...\033[0m\n";

        int computer_column = getComputerMove(board);

        if (computer_column == -1) {
            cout << "\033[1;33m🤝 It's a draw! No valid moves left. 🥱Absolute Stalemate\033[0m\n";
            break;
        }

        updateColumn(board, computer_column, 'O');

        cout << "\033[1;35mComputer (O) placed mark in column: "
             << computer_column << "\033[0m\n";

        printBoard(board);

        if (checkWin(board, 'O')) {
            cout << "\033[1;31m💔 Computer (O) won the game! 🤡📉 Bro got checkmated by a toaster!\033[0m\n";
            break;
        }

        if (isBoardFull(board)) {
            cout << "\033[1;33m🤝 It's a draw! Board is full. 🥱Absolute Stalemate\033[0m\n";
            break;
        }
    }

    return 0;
}
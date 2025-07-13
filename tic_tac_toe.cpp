#include <iostream>
using namespace std;

// Global 3x3 board
char board[3][3];

// Initialize board with numbers 1 to 9
void initializeBoard() {
    char start = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = start++;
}

// Display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

// Check if a player has won
bool checkWin(char player) {
    // Check rows, columns and diagonals
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))   // Column
            return true;

    // Diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Handle player move
bool makeMove(char player) {
    int position;
    cout << "Player " << player << ", enter a position (1-9): ";
    cin >> position;

    if (position < 1 || position > 9) {
        cout << "❌ Invalid position. Try again.\n";
        return false;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "❌ Position already taken. Try again.\n";
        return false;
    }

    board[row][col] = player;
    return true;
}

int main() {
    char currentPlayer = 'X';
    char playAgain;

    do {
        initializeBoard();
        bool gameOver = false;

        cout << "\n🎮 Welcome to Tic-Tac-Toe!\n";
        displayBoard();

        while (!gameOver) {
            if (makeMove(currentPlayer)) {
                displayBoard();

                if (checkWin(currentPlayer)) {
                    cout << "🎉 Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    cout << "🤝 It's a draw!\n";
                    gameOver = true;
                } else {
                    // Switch player
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        cout << "🔁 Do you want to play again? (y/n): ";
        cin >> playAgain;
        currentPlayer = 'X';  // reset to X for new game

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "👋 Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}

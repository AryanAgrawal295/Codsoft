#include <iostream>
#include <vector>
using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>> &board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Main function
int main() {
    char playAgain;
    do {
        // Initialize the game board
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;

        while (true) {
            displayBoard(board);

            // Prompt current player for their move
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3): ";
            cin >> row >> col;

            // Validate input and update the board
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
                board[row - 1][col - 1] = currentPlayer;

                // Check for win or draw
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameWon = true;
                    break;
                } else if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "The game is a draw!\n";
                    break;
                }

                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

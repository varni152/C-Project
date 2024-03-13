#include <iostream>
#include <vector>
using namespace std;

// Function to initialize the game board with empty cells
vector<vector<char>> initializeBoard() {
    return {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
}

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ' ';
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << '|';
        }
        cout << '\n';
        if (i < 2) cout << "  -----\n";
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Check diagonal
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false; // If any cell is empty, game is not a draw
        }
    }
    return true; // All cells are filled, game is a draw
}

int main() {
    vector<vector<char>> board = initializeBoard();
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!\n";

    // Main game loop
    while (true) {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player to enter their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        // Update the board with the player's move
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        board[row - 1][col - 1] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

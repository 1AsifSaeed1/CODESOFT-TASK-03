#include <iostream>
#include <vector>
using namespace std;
void drawBoard(const vector<vector<char>>& board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}
bool checkWin(const vector<vector<char>>& board, char player) 
{
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; 
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; 
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; 
    return false;
}
int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';
    int count = 0;
    cout << "Welcome to Tic Tac Toe!\n";
    drawBoard(board);
    while (count < 9) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            drawBoard(board);
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
            count++;
        } else {
            cout << "Invalid move! Please try again.\n";
        }
    }
    if (count == 9) {
        cout << "It's a draw!\n";
    }
    return 0;
}

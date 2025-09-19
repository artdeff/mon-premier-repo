#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, diagonals
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    for (int j = 0; j < 3; ++j)
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool isDraw(const vector<vector<char>>& board) {
    for (const auto& row : board)
        for (char c : row)
            if (c == ' ')
                return false;
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player = 'X';
    int row, col;

    cout << "Bienvenue au Tic Tac Toe!\n";
    printBoard(board);

    while (true) {
        cout << "Joueur " << player << ", entrez la ligne (1-3) et la colonne (1-3) séparées par un espace : ";
        cin >> row >> col;
        row--; col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Mouvement invalide. Essayez encore.\n";
            continue;
        }

        board[row][col] = player;
        printBoard(board);

        if (isWin(board, player)) {
            cout << "Le joueur " << player << " a gagné!\n";
            break;
        }
        if (isDraw(board)) {
            cout << "Match nul!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
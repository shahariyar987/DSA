#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<int>& board, int row, int col) {
    for (int previousRow = 0; previousRow < row; previousRow++) {
        int previousCol = board[previousRow];

        if (previousCol == col)
            return false;

        if (abs(previousCol - col) ==
            abs(previousRow - row))
            return false;
    }

    return true;
}

bool solveNQueens(vector<int>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            if (solveNQueens(board, row + 1, n))
                return true;

            board[row] = -1;
        }
    }

    return false;
}

void printBoard(const vector<int>& board, int n) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row] == col)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

int main() {
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of queens must be positive.\n";
        return 0;
    }

    vector<int> board(n, -1);

    if (solveNQueens(board, 0, n)) {
        cout << "\nOne solution:\n";
        printBoard(board, n);
    } else {
        cout << "No solution exists for n = " << n << ".\n";
    }

    return 0;
}

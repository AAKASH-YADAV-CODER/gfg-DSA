#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check whether a given Sudoku board is valid
bool isValidSudoku(vector<vector<char>>& board) {
    // Check each row for duplicates
    for (int row = 0; row < 9; row++) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == '.') continue;
            if (seen.count(board[row][i])) return false;
            seen.insert(board[row][i]);
        }
    }

    // Check each column for duplicates
    for (int col = 0; col < 9; col++) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == '.') continue;
            if (seen.count(board[i][col])) return false;
            seen.insert(board[i][col]);
        }
    }

    // Check each 3x3 sub-box for duplicates
    for (int square = 0; square < 9; square++) {
        unordered_set<char> seen;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int row = (square / 3) * 3 + i;
                int col = (square % 3) * 3 + j;
                if (board[row][col] == '.') continue;
                if (seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
            }
        }
    }

    return true;
}

int main() {
    // Example valid board
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    // Call the function and print result
    bool isValid = isValidSudoku(board);
    cout << "Is the Sudoku board valid? " << (isValid ? "Yes" : "No") << endl;

    return 0;
}

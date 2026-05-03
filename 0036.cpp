#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool columns[9][9] = {false};
        bool squares[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int k = 0; k < 9; k++) {
                char x = board[i][k];
                
                if (x != '.') {
                    int num = x - '1';
                    int k2 = (i / 3) * 3 + (k / 3);
                    if (rows[i][num] || columns[k][num] || squares[k2][num]) {
                        return false;
                    }


                    rows[i][num] = true;
                    columns[k][num] = true;
                    squares[k2][num] = true;
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board1 = {
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

    vector<vector<char>> board2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << boolalpha;
    cout << "Test 1: " << sol.isValidSudoku(board1) << " (oczekiwane: true)" << endl;
    cout << "Test 2: " << sol.isValidSudoku(board2) << " (oczekiwane: false)" << endl;

    return 0;
}
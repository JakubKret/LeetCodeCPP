#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n / 2; ++i) {
            int first = i;
            int last = n - 1 - i;
            
            for (int j = 0; j < last - first; ++j) {
                int top = first + j;
                int bottom = last - j;
                
                int top_left = matrix[first][top];
                matrix[first][top] = matrix[bottom][first];
                matrix[bottom][first] = matrix[last][bottom];        
                matrix[last][bottom] = matrix[top][last];
                
                matrix[top][last] = top_left;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    sol.rotate(matrix);

    cout << "Test 1 (Obrocona macierz 3x3):" << endl;
    for (const auto& row : matrix) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    cout << "(oczekiwane:)" << endl;
    cout << "[ 7 4 1 ]" << endl;
    cout << "[ 8 5 2 ]" << endl;
    cout << "[ 9 6 3 ]" << endl;

    return 0;
}

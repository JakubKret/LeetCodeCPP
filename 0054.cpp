#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int rows = matrix.size();
        int columns = matrix[0].size();
        int size = rows * columns;
        vector<int> result;

       
        int currCol = columns; 
        int currRow = rows - 1;
        int state = 0;
        int x = 0; 
        int y = 0;

        while (result.size() < size) {
            switch (state) {
                case 0:
                    for (int i = 0; i < currCol; i++) {
                        result.push_back(matrix[y][x]);
                        if(i < currCol - 1) x++;
                    }
                    currCol--; 
                    y++;       
                    state = 1;
                    break;

                case 1: 
                    for (int i = 0; i < currRow; i++) {
                        result.push_back(matrix[y][x]);
                        if(i < currRow - 1) y++;
                    }
                    currRow--; 
                    x--;
                    state = 2;
                    break;

                case 2: 
                    for (int i = 0; i < currCol; i++) {
                        result.push_back(matrix[y][x]);
                        if(i < currCol - 1) x--;
                    }
                    currCol--;
                    y--;
                    state = 3;
                    break;

                case 3: 
                    for (int i = 0; i < currRow; i++) {
                        result.push_back(matrix[y][x]);
                        if(i < currRow - 1) y--;
                    }
                    currRow--;
                    x++;
                    state = 0;
                    break;
            }
        }
        return result;
    }
};

void printVector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "" : ",");
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Test 1: "; printVector(sol.spiralOrder(matrix1)); cout << " (oczekiwane: [1,2,3,6,9,8,7,4,5])" << endl;

    vector<vector<int>> matrix2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout << "Test 2: "; printVector(sol.spiralOrder(matrix2)); cout << " (oczekiwane: [1,2,3,4,8,12,11,10,9,5,6,7])" << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        curr.reserve(2*n);
        backtrack(result, curr, 0, 0, n);
        return result;
    }
private:
    void backtrack(vector<string>& result, string& curr, int open, int close, int n) {
        if (curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            backtrack(result, curr, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            backtrack(result, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};

void printVector(const vector<string>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "\"" << v[i] << "\"" << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

int main() {
    Solution sol;

    int n1 = 3;
    cout << "Test 1 (n = 3): "; 
    printVector(sol.generateParenthesis(n1)); 
    cout << " (oczekiwane: [\"((()))\",\"(()())\",\"(())()\",\"()(())\",\"()()()\"])" << endl;

    int n2 = 1;
    cout << "Test 2 (n = 1): "; 
    printVector(sol.generateParenthesis(n2)); 
    cout << " (oczekiwane: [\"()\"])" << endl;

    return 0;
}
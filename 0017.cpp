#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        const vector<string> keyboard = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string curr = "";

        backtrack(0, digits, curr, result, keyboard);
        return result;
    }
private:
    void backtrack(int index, const string& digits, string& curr, vector<string>& result, const vector<string>& keyboard) {
        if(index == digits.length()){
            result.push_back(curr);
            return;
        }

        string letters = keyboard[digits[index] - '0'];

        for (char l : letters) {
            curr.push_back(l);
            backtrack(index + 1, digits, curr, result, keyboard);
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

    string digits1 = "23";
    cout << "Test 1 (\"23\"): "; 
    printVector(sol.letterCombinations(digits1)); 
    cout << " (oczekiwane: [\"ad\", \"ae\", \"af\", \"bd\", \"be\", \"bf\", \"cd\", \"ce\", \"cf\"])" << endl;

    string digits2 = "";
    cout << "Test 2 (\"\"):    "; 
    printVector(sol.letterCombinations(digits2)); 
    cout << " (oczekiwane: [])" << endl;

    string digits3 = "2";
    cout << "Test 3 (\"2\"):   "; 
    printVector(sol.letterCombinations(digits3)); 
    cout << " (oczekiwane: [\"a\", \"b\", \"c\"])" << endl;

    return 0;
}
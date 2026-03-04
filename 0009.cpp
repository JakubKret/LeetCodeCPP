#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string xString = to_string(x);
        if(xString.length() == 1)
            return true;
        for(int i = 0; i < xString.length() / 2; i++){
            if(xString[i] != xString[xString.length() - i - 1])
                return false;
        }
        return true;
    }
};


int main() {
    Solution sol;
    int test1 = 121;
    int test2 = -121;
    int test3 = 10;

    cout << "Test 1 (121):  " << (sol.isPalindrome(test1) ? "true" : "false") << " (oczekiwane: true)" << endl;
    cout << "Test 2 (-121): " << (sol.isPalindrome(test2) ? "true" : "false") << " (oczekiwane: false)" << endl;
    cout << "Test 3 (10):   " << (sol.isPalindrome(test3) ? "true" : "false") << " (oczekiwane: false)" << endl;

    return 0;
}
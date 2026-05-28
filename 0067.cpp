#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int x;
        if (a.length() > b.length()) {
            x = a.length();
        } else {
            x = b.length();
        }
        
        string result = "0";
        
        for (int i = 1; i <= x; i++) {
            int loc = result[0] - '0'; 
            
            if (i <= a.length()) {
                loc += a[a.length() - i] - '0';
            }
            if (i <= b.length()) {
                loc += b[b.length() - i] - '0';
            }
            
            if (loc == 0 || loc == 2) {
                result[0] = '0';
            } else if (loc == 1 || loc == 3) {
                result[0] = '1';
            }
            
            if (loc >= 2) {
                result = "1" + result;
            } else {
                if (i < x) {
                    result = "0" + result;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    string a1 = "11", b1 = "1";
    cout << "Test 1 (\"11\", \"1\"):     \"" << sol.addBinary(a1, b1) << "\" (oczekiwane: \"100\")" << endl;

    string a2 = "1010", b2 = "1011";
    cout << "Test 2 (\"1010\", \"1011\"): \"" << sol.addBinary(a2, b2) << "\" (oczekiwane: \"10101\")" << endl;

    return 0;
}
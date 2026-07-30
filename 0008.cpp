#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) {
            return 0;
        }
        
        long long sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            long long current_val = result * sign;
            if (current_val > INT_MAX) return INT_MAX;
            if (current_val < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        result *= sign;
        
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        
        return static_cast<int>(result);
    }
};

int main() {
    Solution sol;

    string s1 = "42";
    cout << "Test 1 (\"42\"):         " << sol.myAtoi(s1) << " (oczekiwane: 42)" << endl;

    string s2 = "   -042";
    cout << "Test 2 (\"   -042\"):    " << sol.myAtoi(s2) << " (oczekiwane: -42)" << endl;

    string s3 = "1337c0d3";
    cout << "Test 3 (\"1337c0d3\"):   " << sol.myAtoi(s3) << " (oczekiwane: 1337)" << endl;

    string s4 = "0-1";
    cout << "Test 4 (\"0-1\"):        " << sol.myAtoi(s4) << " (oczekiwane: 0)" << endl;

    string s5 = "2147483648";
    cout << "Test 5 (\"2147483648\"): " << sol.myAtoi(s5) << " (oczekiwane: 2147483647)" << endl;

    return 0;
}
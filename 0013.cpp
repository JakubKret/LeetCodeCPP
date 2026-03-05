#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'C') {
                if (i + 1 < s.length() && s[i + 1] == 'M') {
                    sum += 900;
                    ++i;
                }
                else if (i + 1 < s.length() && s[i + 1] == 'D') {
                    sum += 400;
                    ++i;
                }
                else
                    sum += 100;
            }
            else if (s[i] == 'M')
                sum += 1000;
            else if (s[i] == 'D')
                sum += 500;
            else if (s[i] == 'X') {
                if (i + 1 < s.length() && s[i + 1] == 'C') {
                    sum += 90;
                    ++i;
                }
                else if (i + 1 < s.length() && s[i + 1] == 'L') {
                    sum += 40;
                    ++i;
                }
                else
                    sum += 10;
            }
            else if (s[i] == 'C')
                sum += 100;
            else if (s[i] == 'L')
                sum += 50;
            else if (s[i] == 'I') {
                if (i + 1 < s.length() && s[i + 1] == 'V') {
                    sum += 4;
                    ++i;
                }
                else if (i + 1 < s.length() && s[i + 1] == 'X') {
                    sum += 9;
                    ++i;
                }
                else
                    sum += 1;
            }
            else if (s[i] == 'X')
                sum += 10;
            else if (s[i] == 'V')
                sum += 5;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    string test1 = "III";
    string test2 = "LVIII";
    string test3 = "MCMXCIV";

    cout << "Test 1 (III):     " << sol.romanToInt(test1) << " (oczekiwane: 3)" << endl;
    cout << "Test 2 (LVIII):   " << sol.romanToInt(test2) << " (oczekiwane: 58)" << endl;
    cout << "Test 3 (MCMXCIV): " << sol.romanToInt(test3) << " (oczekiwane: 1994)" << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        else {
            int maxLen = 1;
            string currentSubstring = "";
            currentSubstring = s[0];
            int i = 1;
            bool elseUsed = 0;

            while (i < s.length()) {
                for (int k = 0; k < currentSubstring.length(); k++) {
                    if (s[i] != currentSubstring[k]) {
                        continue;
                    }
                    else {
                        currentSubstring = currentSubstring.substr(k + 1) + s[i];
                        elseUsed = 1;
                        break;
                    }
                }

                if (elseUsed == 0) {
                    currentSubstring += s[i];
                    if (currentSubstring.length() > maxLen) {
                        maxLen = currentSubstring.length();
                    }
                }

                elseUsed = 0;
                i++;

                if (currentSubstring.length() + (s.length() - i) <= maxLen) {
                    break;
                }
            }
            return maxLen;
        }
    }
};

int main() {
    Solution sol;
    string test1 = "abcabcbb";
    string test2 = "bbbbb";
    string test3 = "pwwkew";
    string test4 = "dvdf";

    cout << "Test 1 (abcabcbb): " << sol.lengthOfLongestSubstring(test1) << " (oczekiwane: 3)" << endl;
    cout << "Test 2 (bbbbb):    " << sol.lengthOfLongestSubstring(test2) << " (oczekiwane: 1)" << endl;
    cout << "Test 3 (pwwkew):   " << sol.lengthOfLongestSubstring(test3) << " (oczekiwane: 3)" << endl;
    cout << "Test 4 (dvdf):     " << sol.lengthOfLongestSubstring(test4) << " (oczekiwane: 3)" << endl;

    return 0;
}
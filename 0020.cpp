#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string open = "";
        for(int i =0; i<s.length();i++)
        {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                open +=s[i];
            }
            else
            {
                char properLetter='e';
                if(open.length()>0)
                {
                    char lastLetter = open[open.length()-1];
                    if(lastLetter =='(')
                        properLetter = ')';
                    else if(lastLetter =='[')
                        properLetter = ']';
                    else
                        properLetter = '}';
                }
                if(properLetter!=s[i])
                    return false;
                else
                    open.pop_back();
            }

            
        }
        if(open.length()>0)
            return false;
        else
            return true;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;

    cout << "Test 1 (\"()\"):     " << sol.isValid("()") << " (oczekiwane: true)" << endl;
    cout << "Test 2 (\"()[]{}\"): " << sol.isValid("()[]{}") << " (oczekiwane: true)" << endl;
    cout << "Test 3 (\"(]\"):     " << sol.isValid("(]") << " (oczekiwane: false)" << endl;
    cout << "Test 4 (\"([])\"):   " << sol.isValid("([])") << " (oczekiwane: true)" << endl;
    cout << "Test 5 (\"([)]\"):   " << sol.isValid("([)]") << " (oczekiwane: false)" << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        while(s[i]==' '){
            i--;
        }
        int k=i;
        while(k>=0&&s[k]!=' '){
            k--;
        }
        return i-k;
    }
};

int main() {
    Solution sol;

    string s1 = "Hello World";
    cout << "Test 1 (\"Hello World\"):                 " << sol.lengthOfLastWord(s1) << " (oczekiwane: 5)" << endl;

    string s2 = "   fly me   to   the moon  ";
    cout << "Test 2 (\"   fly me   to   the moon  \"): " << sol.lengthOfLastWord(s2) << " (oczekiwane: 4)" << endl;

    string s3 = "luffy is still joyboy";
    cout << "Test 3 (\"luffy is still joyboy\"):        " << sol.lengthOfLastWord(s3) << " (oczekiwane: 6)" << endl;

    return 0;
}
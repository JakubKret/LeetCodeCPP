#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool x =1;
        int currentLetterIndex = 0;
        while(x)
        {
            for (int i = 0; i < strs.size(); i++)
            {
                if (currentLetterIndex>strs[i].length())
                {
                    x=0;
                    break;
                }
                if(strs[i][currentLetterIndex]!=strs[0][currentLetterIndex])
                {
                    x=0;
                    break;
                }
                

                
            }
            if(x)
                currentLetterIndex++;
        }
        return strs[0].substr(0,currentLetterIndex);
        
    }
};

int main() {
    Solution sol;
    
    vector<string> test1 = {"flower","flow","flight"};
    vector<string> test2 = {"dog","racecar","car"};

    cout << "Test 1 (flower, flow, flight): \"" << sol.longestCommonPrefix(test1) << "\" (oczekiwane: \"fl\")" << endl;
    cout << "Test 2 (dog, racecar, car):    \"" << sol.longestCommonPrefix(test2) << "\" (oczekiwane: \"\")" << endl;

    return 0;
}
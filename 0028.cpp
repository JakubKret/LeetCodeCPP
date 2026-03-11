#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayL = haystack.length();
        int needL = needle.length();
        if (hayL<needL)
            return -1;
        else
        {
            for (int i = 0; i<(hayL-needL+1);i++)
            {
                for (int k=0; k< needL;k++)
                {
                    if(haystack[i+k]!=needle[k])
                    {
                        break;
                    }
                    else if(k==needL-1)
                        return i;
                }
            }
            return -1;
        }
    }
};

int main() {
    Solution sol;

    string h1 = "sadbutsad", n1 = "sad";
    cout << "Test 1: " << sol.strStr(h1, n1) << " (oczekiwane: 0)" << endl;

    string h2 = "leetcode", n2 = "leeto";
    cout << "Test 2: " << sol.strStr(h2, n2) << " (oczekiwane: -1)" << endl;

    return 0;
}
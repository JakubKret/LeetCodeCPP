#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int left,right,maxL=0,maxR=0;
        
        for(int i=0;i<s.length();i++)
        {
            left=i;
            right=i+1;
            while(left>=0 && right<s.length()){
                if(s[left]==s[right]){
                    if(right-left>maxR-maxL){
                        maxL=left;
                        maxR=right;
                    }
                }
                else
                    break;
                left--;
                right++;
            }
            
            left=i-1;
            right=i+1;
            while(left>=0 && right<s.length()){
                if(s[left]==s[right]){
                    if(right-left>maxR-maxL){
                        maxL=left;
                        maxR=right;
                    }
                }
                else
                    break;
                left--;
                right++;
            }
        }
        return s.substr(maxL,maxR-maxL+1);
        
    }
};

int main() {
    Solution sol;

    string t1 = "babad";
    string t2 = "cbbd";

    cout << "Test 1 (babad): " << sol.longestPalindrome(t1) << " (oczekiwane: bab lub aba)" << endl;
    cout << "Test 2 (cbbd):  " << sol.longestPalindrome(t2) << " (oczekiwane: bb)" << endl;

    return 0;
}
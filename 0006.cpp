#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string verses[numRows];
        int counter=0;
        string final="";
        if(numRows==1){
            return s;
        }
        else{
            for(int i=0; i<s.length();i++){
                if(counter<numRows){
                    verses[counter]+=s[i];
                }
                else{
                    verses[numRows-2-(counter%numRows)]+=s[i];
                }
                if (counter==(numRows+numRows-3))
                    counter=0;
                else
                    counter++;
            }
            for(int i=0;i<numRows;i++)
            {
                final+=verses[i];
            }
        }
        return final;
    }
};

int main() {
    Solution sol;

    string s1 = "PAYPALISHIRING";
    int r1 = 3;
    cout << "Test 1 (PAYPALISHIRING, 3): " << sol.convert(s1, r1) << " (oczekiwane: PAHNAPLSIIGYIR)" << endl;

    string s2 = "PAYPALISHIRING";
    int r2 = 4;
    cout << "Test 2 (PAYPALISHIRING, 4): " << sol.convert(s2, r2) << " (oczekiwane: PINALSIGYAHRPI)" << endl;

    string s3 = "A";
    int r3 = 1;
    cout << "Test 3 (A, 1):              " << sol.convert(s3, r3) << " (oczekiwane: A)" << endl;

    return 0;
}
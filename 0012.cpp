#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string answer ="";
        while (num>0){
            if (num>=1000)
            {
                num-=1000;
                answer+="M";
            }
            else if (num>=900)
            {
                num-=900;
                answer+="CM";
            }
            else if (num>=500)
            {
                num-=500;
                answer+="D";
            }
            else if (num >=400)
            {
                num-=400;
                answer+="CD";
            }
            else if (num>=100)
            {
                num-=100;
                answer+="C";
            }
            else if (num>=90)
            {
                num-=90;
                answer+="XC";
            }
            else if (num>=50)
            {
                num-=50;
                answer+="L";
            }
            else if (num>=40)
            {
                num-=40;
                answer+="XL";
            }
            else if (num>=10)
            {
                num-=10;
                answer+="X";
            }
            else if (num>=9)
            {
                num-=9;
                answer+="IX";
            }
            else if (num>=5)
            {
                num-=5;
                answer+="V";
            }
            else if (num>=4)
            {
                num-=4;
                answer+="IV";
            }
            else if (num>=1)
            {
                num-=1;
                answer+="I";
            }
        }
        return answer;
        
    }
};

int main() {
    Solution sol;
    int test1 = 3749;
    int test2 = 58;
    int test3 = 1994;

    cout << "Test 1 (3749):    " << sol.intToRoman(test1) << " (oczekiwane: MMMDCCXLIX)" << endl;
    cout << "Test 2 (58):      " << sol.intToRoman(test2) << " (oczekiwane: LVIII)" << endl;
    cout << "Test 3 (1994):    " << sol.intToRoman(test3) << " (oczekiwane: MCMXCIV)" << endl;

    return 0;
}
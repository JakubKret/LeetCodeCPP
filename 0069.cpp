#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long sqrt = 0;
        while(sqrt*sqrt<=x) {
            sqrt++;
        }
        return sqrt-1;
    }
};

int main() {
    Solution sol;

    int x1 = 4;
    cout << "Test 1 (x = 4):  " << sol.mySqrt(x1) << " (oczekiwane: 2)" << endl;

    int x2 = 8;
    cout << "Test 2 (x = 8):  " << sol.mySqrt(x2) << " (oczekiwane: 2)" << endl;

    int x3 = 0;
    cout << "Test 3 (x = 0):  " << sol.mySqrt(x3) << " (oczekiwane: 0)" << endl;

    return 0;
}

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int last = x % 10;
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && last > 7)) {
                return 0;
            }
            
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && last < -8)) {
                return 0;
            }
            
            rev = rev * 10 + last;
        }
        return rev;
    }
};

int main() {
    Solution sol;

    int t1 = 123;
    cout << "Test 1 (123):  " << sol.reverse(t1) << " (oczekiwane: 321)" << endl;

    int t2 = -123;
    cout << "Test 2 (-123): " << sol.reverse(t2) << " (oczekiwane: -321)" << endl;

    int t3 = 120;
    cout << "Test 3 (120):  " << sol.reverse(t3) << " (oczekiwane: 21)" << endl;

    return 0;
}
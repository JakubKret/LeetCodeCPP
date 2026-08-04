#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int prev2 = 1;
        int prev1 = 2;
        int current = 0;

        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};

int main() {
    Solution sol;

    int n1 = 2;
    cout << "Test 1 (n = 2): " << sol.climbStairs(n1) << " (oczekiwane: 2)" << endl;

    int n2 = 3;
    cout << "Test 2 (n = 3): " << sol.climbStairs(n2) << " (oczekiwane: 3)" << endl;

    int n3 = 5;
    cout << "Test 3 (n = 5): " << sol.climbStairs(n3) << " (oczekiwane: 8)" << endl;

    return 0;
}
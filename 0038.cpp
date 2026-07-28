#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        else {
            string res = "1";
            for (int i = 1; i < n; i++) {
                res = rle(res);
            }
            return res;
        }
    }
private:
    string rle(string prev) {
        int index = 0;
        string result = "";
        while (index < prev.length()) {
            int count = 1;
            while (index + 1 < prev.length() && prev[index] == prev[index + 1]) {
                count++;
                index++;
            }
            result += to_string(count) + prev[index];
            index++;
        }
        return result;
    }
};

int main() {
    Solution sol;

    int n1 = 1;
    cout << "Test 1 (n = 1): " << sol.countAndSay(n1) << " (oczekiwane: \"1\")" << endl;

    int n2 = 4;
    cout << "Test 2 (n = 4): " << sol.countAndSay(n2) << " (oczekiwane: \"1211\")" << endl;

    return 0;
}
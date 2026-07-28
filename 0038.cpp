#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string current = "1";

        for (int i = 1; i < n; i++) {
            string nextStr;
            nextStr.reserve(current.length() * 2);

            int count = 1;
            for (int j = 0; j < current.length(); j++) {
                if (j + 1 < current.length() && current[j] == current[j + 1]) {
                    count++;
                } else {
                    nextStr.push_back(count + '0');
                    nextStr.push_back(current[j]);

                    count = 1;
                }
            }
            current = std::move(nextStr);
        }

        return current;
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
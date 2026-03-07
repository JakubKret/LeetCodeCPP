#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastNumber = nums[0];
        int k=1;
        int nextDistinctNumberIndex = 1;
        for (int i =1; i < nums.size(); i++)
        {
            if (nums[i]!=lastNumber)
            {
                k++;
                lastNumber=nums[i];
                nums[nextDistinctNumberIndex] = lastNumber;
                nextDistinctNumberIndex++;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(test1);
    cout << "Test 1: [";
    for(int i = 0; i < k1; i++) cout << test1[i] << (i == k1 - 1 ? "" : ",");
    cout << "] (oczekiwane: [1,2])" << endl;

    vector<int> test2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(test2);
    cout << "Test 2: [";
    for(int i = 0; i < k2; i++) cout << test2[i] << (i == k2 - 1 ? "" : ",");
    cout << "] (oczekiwane: [0,1,2,3,4])" << endl;

    return 0;
}
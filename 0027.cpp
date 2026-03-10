#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=0;
        int count=0;
        for(int i; i < nums.size(); i++)
        {
            if(nums[i]!=val)
            {
                nums[index]=nums[i];
                index++;
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> test1_nums = {3,2,2,3};
    int test1_val = 3;
    cout << "Test 1: " << sol.removeElement(test1_nums, test1_val) << " (oczekiwane: 2)" << endl;

    vector<int> test2_nums = {0,1,2,2,3,0,4,2};
    int test2_val = 2;
    cout << "Test 2: " << sol.removeElement(test2_nums, test2_val) << " (oczekiwane: 5)" << endl;

    return 0;
}
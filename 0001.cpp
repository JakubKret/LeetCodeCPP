#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool finish = false;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {

            for (int k = i+1; k< nums.size();k++)
            {
                if (nums[i]+nums[k]==target)
                {
                    result = {i,k};
                    return result;
                    finish = true;
                    break;
                }
            }

            if(finish)
                break;
        }
        return result;

    }
};

void printVector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << (i == v.size() - 1 ? "" : ",");
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<int> test1_nums = {2,7,11,15};
    int test1_target = 9;
    cout << "Test 1: "; printVector(sol.twoSum(test1_nums, test1_target)); cout << " (oczekiwane: [0,1])" << endl;

    vector<int> test2_nums = {3,2,4};
    int test2_target = 6;
    cout << "Test 2: "; printVector(sol.twoSum(test2_nums, test2_target)); cout << " (oczekiwane: [1,2])" << endl;

    vector<int> test3_nums = {3,3};
    int test3_target = 6;
    cout << "Test 3: "; printVector(sol.twoSum(test3_nums, test3_target)); cout << " (oczekiwane: [0,1])" << endl;

    return 0;
}
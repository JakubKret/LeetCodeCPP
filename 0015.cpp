#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return triplets;
    }
};

void printMatrix(vector<vector<int>> m) {
    cout << "[";
    for (int i = 0; i < m.size(); i++) {
        cout << "[";
        for (int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << (j == m[i].size() - 1 ? "" : ",");
        }
        cout << "]" << (i == m.size() - 1 ? "" : ",");
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<int> nums1 = {-1,0,1,2,-1,-4};
    cout << "Test 1 ({-1,0,1,2,-1,-4}): "; printMatrix(sol.threeSum(nums1)); cout << " (oczekiwane: [[-1,-1,2],[-1,0,1]])" << endl;

    vector<int> nums2 = {0,1,1};
    cout << "Test 2 ({0,1,1}):           "; printMatrix(sol.threeSum(nums2)); cout << " (oczekiwane: [])" << endl;

    vector<int> nums3 = {0,0,0};
    cout << "Test 3 ({0,0,0}):           "; printMatrix(sol.threeSum(nums3)); cout << " (oczekiwane: [[0,0,0]])" << endl;

    return 0;
}
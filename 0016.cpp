#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
                
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int current_sum = nums[i] + nums[j] + nums[k];
                                        
                    if (std::abs(current_sum - target) < std::abs(closest_sum - target)) {
                        closest_sum = current_sum;
                    }
                }
            }
        }
        return closest_sum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Test 1 ({-1, 2, 1, -4}, 1): " << sol.threeSumClosest(nums1, target1) << " (oczekiwane: 2)" << endl;

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Test 2 ({0, 0, 0}, 1):       " << sol.threeSumClosest(nums2, target2) << " (oczekiwane: 0)" << endl;

    return 0;
}
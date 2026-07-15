#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];

                if (current_sum == target) {
                    return current_sum;
                }

                if (std::abs(target - current_sum) < std::abs(target - closest_sum)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    left++;
                } else {
                    right--;
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
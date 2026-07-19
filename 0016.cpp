#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int min_sum = nums[i] + nums[i + 1] + nums[i + 2];
            if (min_sum > target) {
                if (std::abs(min_sum - target) < std::abs(closest_sum - target)) {
                    closest_sum = min_sum;
                }
                break;
            }

            int max_sum = nums[i] + nums[n - 2] + nums[n - 1];
            if (max_sum < target) {
                if (std::abs(max_sum - target) < std::abs(closest_sum - target)) {
                    closest_sum = max_sum;
                }
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (current_sum == target) return current_sum;

                if (std::abs(target - current_sum) < std::abs(target - closest_sum)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    int current_left = nums[left];
                    while (left < right && nums[left] == current_left) left++;
                } else {
                    int current_right = nums[right];
                    while (left < right && nums[right] == current_right) right--;
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
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0, index2 = 0;
        int target = nums1.size() + nums2.size();
        int curr = 0;
        int prev = 0;
        
        for (int i = 0; i <= target / 2; i++) {
            prev = curr;
            
            if (index1 < nums1.size() && (index2 == nums2.size() || nums1[index1] <= nums2[index2])) {
                curr = nums1[index1];
                index1++;
            } else {
                curr = nums2[index2];
                index2++;
            }
        }
        
        if (target % 2 == 1) {
            return curr;
        } else {
            return (prev + curr) / 2.0; 
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test 1 ({1, 3}, {2}):       " << sol.findMedianSortedArrays(nums1, nums2) << " (oczekiwane: 2.0)" << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Test 2 ({1, 2}, {3, 4}):    " << sol.findMedianSortedArrays(nums3, nums4) << " (oczekiwane: 2.5)" << endl;

    return 0;
}
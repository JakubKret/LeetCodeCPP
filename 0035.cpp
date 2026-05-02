#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int x=nums.size(),left=0,right=x,index;
        if(nums[0]>=target)  return 0;
        while(left<right) {
            index=left+(right-left)/2;
            if(nums[index]>=target){
                if(nums[index-1]<=target){
                    if (nums[index-1]==target) return index-1;
                    else return index;
                }
                else{
                    right=index;
                }
            }
            else{
                left=index+1;
            }
        }
        return index+1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,3,5,6};
    cout << "Test 1 ([1,3,5,6], 5): " << sol.searchInsert(nums1, 5) << " (oczekiwane: 2)" << endl;

    vector<int> nums2 = {1,3,5,6};
    cout << "Test 2 ([1,3,5,6], 2): " << sol.searchInsert(nums2, 2) << " (oczekiwane: 1)" << endl;

    vector<int> nums3 = {1,3,5,6};
    cout << "Test 3 ([1,3,5,6], 7): " << sol.searchInsert(nums3, 7) << " (oczekiwane: 4)" << endl;

    return 0;
}
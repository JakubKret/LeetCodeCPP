#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=nums.size();
        int left = 0;
        int right = x - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                break;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (left>right) return {-1,-1};
        int i=mid;
        while(i>=0 && nums[i]==target){
            i--;
        }

        int k=mid;
        while(k<x&&nums[k]==target){
            k++;
        }


        return {i+1,k-1};

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

    vector<int> nums1 = {5,7,7,8,8,10};
    int target1 = 8;
    cout << "Test 1: "; printVector(sol.searchRange(nums1, target1)); cout << " (oczekiwane: [3,4])" << endl;

    vector<int> nums2 = {5,7,7,8,8,10};
    int target2 = 6;
    cout << "Test 2: "; printVector(sol.searchRange(nums2, target2)); cout << " (oczekiwane: [-1,-1])" << endl;

    vector<int> nums3 = {};
    int target3 = 0;
    cout << "Test 3: "; printVector(sol.searchRange(nums3, target3)); cout << " (oczekiwane: [-1,-1])" << endl;

    return 0;
}
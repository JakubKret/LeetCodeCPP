#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int right=height.size()-1, left=0,mini,result,best=0;
        while(right!=left){
            mini=min(height[right],height[left]);
            result=mini*(right-left);
            if(result>best)     best=result;
            if(mini == height[right])    right--;
            else    left++;
        }
        return best;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1,8,6,2,5,4,8,3,7};
    cout << "Test 1: " << sol.maxArea(test1) << " (oczekiwane: 49)" << endl;

    vector<int> test2 = {1,1};
    cout << "Test 2: " << sol.maxArea(test2) << " (oczekiwane: 1)" << endl;

    return 0;
}
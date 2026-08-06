#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { 
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Pomocnicza funkcja do wypisywania wektora
void printVector(const vector<int>& nums) {
    cout << "[ ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Przed sortowaniem: ";
    printVector(nums);

    sol.sortColors(nums);

    cout << "Po sortowaniu:    ";
    printVector(nums);
    cout << "(oczekiwane: [ 0 0 1 1 2 2 ])" << endl;

    return 0;
}
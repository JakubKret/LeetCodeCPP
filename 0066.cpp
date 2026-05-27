#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int x=digits.size()-1;
        digits[x]++;
        if(digits[x]<9){
            return digits;
        }
        
        while(x>=0){
            
            if(digits[x]>9){
                digits[x]=0;
                if (x-1 == -1)  digits.insert(digits.begin(),1);
                else
                    digits[x-1]++;    
            }
            else
                return digits;
            x--;
        }
        return digits;
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

    vector<int> digits1 = {1,2,3};
    cout << "Test 1: "; printVector(sol.plusOne(digits1)); cout << " (oczekiwane: [1,2,4])" << endl;

    vector<int> digits2 = {4,3,2,1};
    cout << "Test 2: "; printVector(sol.plusOne(digits2)); cout << " (oczekiwane: [4,3,2,2])" << endl;

    vector<int> digits3 = {9};
    cout << "Test 3: "; printVector(sol.plusOne(digits3)); cout << " (oczekiwane: [1,0])" << endl;

    return 0;
}
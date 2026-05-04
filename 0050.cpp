#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long N=n;
        if(n==0 || x==1)    return 1;
        else{
            if(n<0){
                x=1/x;
                N=-N;
            }
            double result=1;
            double curr=x;
            while(N>0){
                if(N%2==1)
                    result*=curr;
                curr*=curr;
                N/=2;
            }
            return result;
        }
    }
};

int main() {
    Solution sol;

    double x1 = 2.00000;
    int n1 = 10;
    cout << "Test 1 (2.00000, 10): " << fixed << setprecision(5) << sol.myPow(x1, n1) << " (oczekiwane: 1024.00000)" << endl;

    double x2 = 2.10000;
    int n2 = 3;
    cout << "Test 2 (2.10000, 3):  " << fixed << setprecision(5) << sol.myPow(x2, n2) << " (oczekiwane: 9.26100)" << endl;

    double x3 = 2.00000;
    int n3 = -2;
    cout << "Test 3 (2.00000, -2): " << fixed << setprecision(5) << sol.myPow(x3, n3) << " (oczekiwane: 0.25000)" << endl;

    return 0;
}
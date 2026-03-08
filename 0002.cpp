#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ci=0;
        ListNode result(0);
        ListNode* resultCursor = &result;
        int l1Val, l2Val, valSum;
        while (!(l1 == nullptr && l2 == nullptr))
        {
            if (l1 == nullptr)
            {
                l1Val = 0;
            }
            else
                l1Val = l1 -> val;
            if (l2 == nullptr)
            {
                l2Val = 0;
            }
            else
                l2Val = l2 -> val;
            valSum = l1Val+l2Val+ci;
            ci=0;
            if(valSum>=10)
                ci = 1;
            resultCursor->next = new ListNode(valSum%10);
            resultCursor = resultCursor ->next;
            if(l1!=nullptr)
                l1 =l1 ->next;
            if(l2!=nullptr)
                l2 = l2 ->next;
        }
        if (ci ==1){
            resultCursor->next = new ListNode(1);
        }
        return result.next;
    }
};

ListNode* createList(vector<int> nums) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    for (int x : nums) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy.next;
}

void printList(ListNode* l) {
    cout << "[";
    while (l) {
        cout << l->val << (l->next ? "," : "");
        l = l->next;
    }
    cout << "]";
}

int main() {
    Solution sol;

    ListNode* l1_1 = createList({2,4,3});
    ListNode* l1_2 = createList({5,6,4});
    cout << "Test 1: "; printList(sol.addTwoNumbers(l1_1, l1_2)); cout << " (oczekiwane: [7,0,8])" << endl;

    ListNode* l2_1 = createList({0});
    ListNode* l2_2 = createList({0});
    cout << "Test 2: "; printList(sol.addTwoNumbers(l2_1, l2_2)); cout << " (oczekiwane: [0])" << endl;

    ListNode* l3_1 = createList({9,9,9,9,9,9,9});
    ListNode* l3_2 = createList({9,9,9,9});
    cout << "Test 3: "; printList(sol.addTwoNumbers(l3_1, l3_2)); cout << " (oczekiwane: [8,9,9,9,0,0,0,1])" << endl;

    return 0;
}
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode result(0);
        ListNode* current = &result;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        return result.next;
    }
};

// Pomocnicza funkcja do wypisywania listy
void printList(ListNode* head) {
    cout << "[ ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]" << endl;
}

// Pomocnicza funkcja do zwalniania pamięci
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;

    // Test: list1 = [1, 2, 4], list2 = [1, 3, 4] -> oczekiwane: [1, 1, 2, 3, 4, 4]
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    cout << "Lista 1: ";
    printList(list1);
    cout << "Lista 2: ";
    printList(list2);

    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Po scaleniu: ";
    printList(merged);
    cout << "(oczekiwane: [ 1 1 2 3 4 4 ])" << endl;

    freeList(merged);

    return 0;
}
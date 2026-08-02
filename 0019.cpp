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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
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

    // Test: [1, 2, 3, 4, 5], n = 2 -> oczekiwane: [1, 2, 3, 5]
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    
    cout << "Przed usunieciem: ";
    printList(head);

    head = sol.removeNthFromEnd(head, 2);

    cout << "Po usunieciu (n = 2): ";
    printList(head);
    cout << "(oczekiwane: [ 1 2 3 5 ])" << endl;

    freeList(head);

    return 0;
}
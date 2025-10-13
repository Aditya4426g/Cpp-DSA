#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//206 leet code
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;   // store next node
            curr->next = prev;   // reverse current node's pointer
            prev = curr;         // move prev to current
            curr = next;         // move to next node
        }
        return prev; // new head
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create a simple linked list for testing
ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

int main() {
    Solution s;

    ListNode* head = createList();
    cout << "Original List: ";
    printList(head);

    head = s.reverseList(head);
    cout << "Reversed List: ";
    printList(head);

    return 0;
}

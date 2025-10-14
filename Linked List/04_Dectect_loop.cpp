#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 141 leetcode
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    // Example test case
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creates a cycle (pointing back to 'second')

    Solution sol;
    bool result = sol.hasCycle(head);

    if (result)
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}

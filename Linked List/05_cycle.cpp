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
// 142 leetcode
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle=false;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          
            fast = fast->next->next;    

            if (slow == fast) {
                isCycle=true;
                break;
            }
        }
        if(!isCycle){
            return NULL;
        }


        slow = head;
        ListNode* prev;
        while(slow !=fast){
            slow =slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=NULL;//remove cycle
        return slow;
    }
};

int main() {
    // Example list creation
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // creates a cycle at node with value 2

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart != NULL)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}

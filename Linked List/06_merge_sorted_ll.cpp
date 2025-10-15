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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // Base case
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // Recursive merge
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

// Helper function to insert a node at the end
void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first sorted list: 1 -> 3 -> 5
    ListNode* list1 = NULL;
    insertNode(list1, 1);
    insertNode(list1, 3);
    insertNode(list1, 5);

    // Create second sorted list: 2 -> 4 -> 6
    ListNode* list2 = NULL;
    insertNode(list2, 2);
    insertNode(list2, 4);
    insertNode(list2, 6);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Solution s;
    ListNode* merged = s.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

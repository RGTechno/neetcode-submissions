/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        int indexToRemove = (length - n);

        if (indexToRemove == 0) {
            // remove at head
            head = head->next;
            return head;
        }

        if (indexToRemove == length - 1) {
            // remove tail node
            ListNode* temp1 = head;
            while (temp1->next->next) {
                temp1 = temp1->next;
            }
            temp1->next = nullptr;
            return head;
        }

        ListNode* c = head;
        ListNode* p = NULL;

        for (int i = 0; i < indexToRemove; i++) {
            p = c;
            c = c->next;
        }
        p->next = c->next;

        return head;
    }
};

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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        while (temp->next && temp->next->next) {
            ListNode* p = temp;
            while (p->next->next) {
                p = p->next;
            }
            if (temp != p) {
                ListNode* c = temp->next;
                temp->next = p->next;
                p->next->next = c;
                p->next = nullptr;
                temp = c;
            }
        }
    }
};

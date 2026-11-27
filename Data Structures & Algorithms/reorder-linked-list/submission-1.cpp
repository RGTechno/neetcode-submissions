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
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is middle point;

        ListNode* p = NULL;
        ListNode* c = slow;
        while (c) {
            ListNode* t = c->next;
            c->next = p;
            p = c;
            c = t;
        }

        // middle point after reversing 2nd half is "p"
        
        // merge
        ListNode* start=head;
        while(p->next){
            ListNode* stemp=start->next;
            ListNode* ptemp=p->next;
            start->next=p;
            p->next=stemp;
            start=stemp;
            p=ptemp;
        }
    }
};

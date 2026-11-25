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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // list 1 and 2 are empty
        if (list1 == NULL && list2 == NULL) return NULL;

        // list 1 is empty
        if (list1 == NULL) return list2;

        // list2 is empty
        if (list2 == NULL) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newHead = NULL;
        ListNode* newTemp = NULL;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                ListNode* nn = new ListNode(temp1->val);
                if (newHead == NULL) {
                    newHead = nn;
                    newTemp = newHead;
                } else {
                    newTemp->next = nn;
                    newTemp = nn;
                }
                temp1 = temp1->next;
            } else {
                ListNode* nn = new ListNode(temp2->val);
                if (newHead == NULL) {
                    newHead = nn;
                    newTemp = newHead;
                } else {
                    newTemp->next = nn;
                    newTemp = nn;
                }
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL) {
            ListNode* nn = new ListNode(temp1->val);
            if (newHead == NULL) {
                newHead = nn;
                newTemp = newHead;
            } else {
                newTemp->next = nn;
                newTemp = nn;
            }
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            ListNode* nn = new ListNode(temp2->val);
            if (newHead == NULL) {
                newHead = nn;
                newTemp = newHead;
            } else {
                newTemp->next = nn;
                newTemp = nn;
            }
            temp2 = temp2->next;
        }
        return newHead;
    }
};

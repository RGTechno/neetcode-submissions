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
        if(!list1 && !list2) return NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* nn=new ListNode(0);

        ListNode* l1=list1;
        ListNode* l2=list2;

        while(l1 && l2){
            if(l1->val<=l2->val){
                nn->next=l1;
                nn=l1;
                l1=l1->next;
            }else{
                nn->next=l2;
                nn=l2;
                l2=l2->next;
            }
        }
        if(l1){
            nn->next=l1;
        }
        if(l2){
            nn->next=l2;
        }

        if(list1->val<=list2->val) return list1;
        return list2;
    }
};

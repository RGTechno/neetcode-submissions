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
    pair<int, int> getNumberAndCarry(int n) {
        int number = n % 10;
        int carry = n / 10;

        return {number, carry};
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = l1;
        ListNode* list2 = l2;

        int carry = 0;

        ListNode* newHead = NULL;
        ListNode* mover = NULL;

        while (list1 && list2) {
            int n = list1->val + list2->val + carry;
            pair<int, int> x = getNumberAndCarry(n);
            int number = x.first;
            carry = x.second;

            ListNode* nn = new ListNode(number);
            if (newHead == NULL) {
                newHead = nn;
                mover = nn;
            }else{
                mover->next=nn;
                mover=nn;
            }
            list1=list1->next;
            list2=list2->next;
        }
        while(list1){
            int n=list1->val+carry;
            pair<int, int> x = getNumberAndCarry(n);
            int number = x.first;
            carry = x.second;

            ListNode* nn = new ListNode(number);
            mover->next=nn;
            mover=nn;

            list1=list1->next;
        }
        while(list2){
            int n=list2->val+carry;
            pair<int, int> x = getNumberAndCarry(n);
            int number = x.first;
            carry = x.second;

            ListNode* nn = new ListNode(number);
            mover->next=nn;
            mover=nn;

            list2=list2->next;
        }

        if(carry){
            ListNode* nn = new ListNode(carry);
            mover->next=nn;
            mover=nn;
        }

        return newHead;
    }
};

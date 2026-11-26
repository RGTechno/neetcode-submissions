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
    bool hasCycle(ListNode* head) {
        ListNode* temp=head;
        unordered_set<ListNode*> st;

        while(temp){
            if(st.find(temp)!=st.end()){
                // index already seen
                return true;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};

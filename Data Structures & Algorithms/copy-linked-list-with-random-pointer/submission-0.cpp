/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
       

        Node* newHead=NULL;
        Node* t1=NULL;
        Node* t = head;
        
        while (t) {
            Node* nn = new Node(t->val);
            mp[t]=nn;
            if (newHead == NULL) {
                newHead = nn;
            } else {
                t1->next = nn;
            }
            t1 = nn;
            t=t->next;
        }

        Node* start=newHead;

        while(temp){
            if(temp->random==nullptr){
                start->random=nullptr;
            }
            start->random=mp[temp->random];
            start=start->next;
            temp=temp->next;
        }

        return newHead;
    }
};

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
        Node* ptr1;Node* ptr2;Node* cur1;Node* cur2;Node* head2;
        unordered_map<Node*,Node*> mp;
        ptr1 = head;
        if(head==NULL) return NULL;
        else{
           head2 = new Node(ptr1->val);
           mp[ptr1] = head2;
            cur1 = head2;
            while(ptr1->next!=NULL){
                ptr1 = ptr1->next;
                cur1->next = new Node(ptr1->val);
                mp[ptr1] = cur1->next;
                cur1 = cur1->next;
            }
        }
        ptr2 = head; cur2 = head2;
        while(ptr2!=NULL){
            if(ptr2->random!=NULL) cur2->random = mp[ptr2->random];
            ptr2 = ptr2->next;
            cur2 = cur2->next;
        }
        return head2;
    }
};

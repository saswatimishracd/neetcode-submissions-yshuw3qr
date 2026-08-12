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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        ListNode* current = second;
        while(current!=NULL){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        ListNode* l1 = head;
        ListNode* l2 = prev;
        ListNode* next1 = l1;
        ListNode* next2 = l2;
        while(l1!=NULL && l2!=NULL){
            next1 = next1->next;
            next2 = next2->next;
            l1->next = l2;
            l2->next = next1;
            l1=next1;
            l2=next2;
        }

    }
};

// step1 :- Find the middle of the linked list
// step 2 :- Reverse the linked list from that middle to end
// step 3 :- Connect both lists alternatively
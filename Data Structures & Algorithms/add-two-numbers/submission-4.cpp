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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        int remainder = 0;
        while(ptr1!=NULL || ptr2!=NULL){
        int value1 = 0; int value2 = 0;
            if(ptr1!=NULL) value1 = ptr1->val;
            if(ptr2!=NULL) value2 = ptr2->val;
            if(ptr1==NULL) value1=0;
            if(ptr2==NULL) value2=0;

            int sum = value1 + value2 + carry;
            carry = sum/10;
            remainder = sum%10;
            ListNode* newNode = new ListNode(remainder);
            temp->next = newNode;
            temp = newNode;
            if(ptr1!=NULL) ptr1 = ptr1->next;
            if(ptr2!=NULL) ptr2 = ptr2->next;
        }
        if(carry!=0){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return dummy.next;
    }
};

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        ListNode* temp = &dummy;
        temp->next = head;
        int counter = 0;
        ListNode* leftNode = head;
        ListNode* beforeLeft = temp;
            while(left-1 != counter){
            beforeLeft = beforeLeft->next;
            counter++;
            }
        leftNode = beforeLeft->next;
        counter = 0;
        ListNode* rightNode = temp;
        while(right!=counter){
            rightNode = rightNode->next;
            counter++;
        }
        ListNode* afterRight = rightNode->next; 
        ListNode* prev = leftNode;
        ListNode* cur = prev->next;
        ListNode* next = cur->next;
        while(cur!=afterRight){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        beforeLeft->next = rightNode;
        leftNode->next = afterRight;
        return dummy.next;
    }
};
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
        ListNode* current1 = list1;
        ListNode* current2 = list2;
        ListNode* prev = list1;
        ListNode* head = list1;
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        if (list1->val <= list2->val) {
            head = list1;
            prev = head;
            current1 = list1->next;
        }

        else {
            head = list2;
            prev = head;
            current2 = list2->next;
        }

        while (current1 != NULL && current2 != NULL) {
            if (current1->val <= current2->val) {
                prev->next = current1;
                current1 = current1->next;
                prev = prev->next;
            }

            else {
                prev->next = current2;
                current2 = current2->next;
                prev = prev->next;
            }
        }

        while (current1 != NULL) {
            prev->next = current1;
            current1 = current1->next;
            prev = prev->next;
        }

        while (current2 != NULL) {
            prev->next = current2;
            current2 = current2->next;
            prev = prev->next;
        }
        return head;
    }
};

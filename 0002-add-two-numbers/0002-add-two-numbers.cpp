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
        ListNode* head = l1;
        ListNode* prev = NULL;
        int carry = 0;
        while(l1 && l2){
            l1->val += l2->val + carry;
            carry = l1->val/10;
            l1->val = l1->val%10;
            prev = l1;
            l1=l1->next;
            l2=l2->next;
        }

        if(!l1 && l2){
            l1 = l2;
            prev->next = l2;
        }

        while(carry && l1){
            l1->val += carry;
            carry = l1->val/10;
            l1->val = l1->val%10;
            prev = l1;
            l1 = l1->next;
        }
        if(carry){
            ListNode* n = new ListNode(carry);
            prev->next = n;
        }
        return head;
    }
};
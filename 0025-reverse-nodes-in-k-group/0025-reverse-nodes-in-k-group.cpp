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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        if(head == NULL || head->next == NULL || k<=1 ){
            return head;
        }

        ListNode* PrevGrp = dummy;
        while(1){
            ListNode* kth = PrevGrp;
            for(int i = 0; i<k && kth!=NULL ;i++){
                kth = kth->next;
            }
            if(kth == NULL){
                break;
            }
            ListNode* NextGrp = kth->next;
            ListNode* GroupStart = PrevGrp->next;
            ListNode* curr = PrevGrp->next;
            ListNode* prev = NextGrp;
            while(curr != NextGrp){
                ListNode* next = curr->next;
                curr->next = prev;
                prev=curr;
                curr = next;
            }
            PrevGrp->next = kth;
            PrevGrp = GroupStart;
        }
        return dummy->next;
    }
};
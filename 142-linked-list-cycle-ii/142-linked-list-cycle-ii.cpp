/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head, *temp=head;
        
        if(!head)
            return NULL;
        
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        
        if(slow!=fast || (slow==fast && slow->next==NULL))
            return NULL;
        
        while(temp!=slow) {
            temp=temp->next;
            slow=slow->next;
        }
        
        return slow;
    }
};
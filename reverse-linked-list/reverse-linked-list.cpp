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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *prev = NULL, *curr, *nex;
        curr = head;
        while(curr!=NULL) {
            nex = curr->next;        
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
};
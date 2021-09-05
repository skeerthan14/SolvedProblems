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
        ListNode* l3, *head;
        l3 = new ListNode(-1);
        head = l3;
        // cout<<l3->val<<endl;
        // return nullptr;
        int c = 0,s=0;
        while(l1 && l2) {
            s = l1->val + l2->val + c;
            l3->next = new ListNode(s%10);
            c = s/10;
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            s = l1->val + c;
            l3->next = new ListNode(s%10);
            c = s/10;
            l3 = l3->next;
            l1 = l1->next;
        }
        while(l2) {
            s = l2->val + c;
            l3->next = new ListNode(s%10);
            c = s/10;
            l3 = l3->next;
            l2 = l2->next;
        }
        if(c) l3->next = new ListNode(c);
        return head->next;
    }
};
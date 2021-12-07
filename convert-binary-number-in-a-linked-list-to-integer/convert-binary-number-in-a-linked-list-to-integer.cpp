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
    int getDecimalValue(ListNode* head) {
        stack<int> s;
        while(head!=NULL) {
            s.push(head->val);
            head = head->next;
        }
        int ans = 0, i=0;
        while(!s.empty()) {
            ans += s.top()*pow(2, i);
            i++;
            s.pop();
        }
        return ans;
    }
};
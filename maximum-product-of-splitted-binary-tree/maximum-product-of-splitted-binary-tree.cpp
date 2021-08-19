/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long ans = INT_MIN, tsum, m = 1e9+7;
    int getSum(TreeNode* root) {
        if(root==NULL) return 0;
        int s =  root->val + getSum(root->left) + getSum(root->right);
        ans = max(ans, (tsum-s)*s);
        return s;
        
    }
    int maxProduct(TreeNode* root) {
        tsum = getSum(root);
        getSum(root);
        return ans%m;
        
    }
};
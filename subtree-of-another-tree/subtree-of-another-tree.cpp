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
    bool isIdentical(TreeNode* r, TreeNode* s) {
        if(!r || !s) return r==s;
        return (r->val == s->val && isIdentical(r->left, s->left) && isIdentical(r->right, s->right)); 
        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return true;
        if(isIdentical(root, subRoot)) return true;
        return isSubtree(root->left, subRoot)||isSubtree(root->right, subRoot);
    }
};
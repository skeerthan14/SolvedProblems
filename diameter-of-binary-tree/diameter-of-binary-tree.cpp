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
private:
    int getMax(TreeNode* root, int& d) {
        if(root==nullptr) return 0;
        int l = getMax(root->left, d);
        int r = getMax(root->right, d);
        d = max(d, l+r);
        return 1+max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = INT_MIN;
        getMax(root, d);
        return d;
    }
};
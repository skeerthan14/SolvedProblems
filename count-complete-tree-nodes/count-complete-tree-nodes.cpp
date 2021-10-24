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
    int H(TreeNode* root, bool l) {
        int h = 0;
        while(root!=NULL) {
            h++;
            if(l)
                root = root->left;
            else root = root->right;
        }
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int l = H(root, true);
        int r = H(root, false);
        if(l==r) {
            return (1<<l) - 1;
        }
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};
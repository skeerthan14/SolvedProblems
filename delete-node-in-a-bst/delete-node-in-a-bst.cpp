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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val>key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val<key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left) {
                TreeNode* r = root->right;
                delete root;
                return r;
            } else if (!root->right) {
                TreeNode* r = root->left;
                delete root;
                return r;
            } else {
                TreeNode* r = root->left;
                while(r->right) r = r->right;
                root->val = r->val;
                root->left = deleteNode(root->left, r->val);
            }
        }
        return root;
    }
};
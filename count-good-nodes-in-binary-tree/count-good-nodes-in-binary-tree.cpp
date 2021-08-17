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
    int c = 0;
    int goodNodes(TreeNode* root, int ma = INT_MIN) {
        if(root==nullptr) return c;
        if(root->val>=ma) {
            c++;
            ma = root->val;
        }
        goodNodes(root->left, ma);
        goodNodes(root->right, ma);
        // cout<<l<<" "<<m<<endl;
        return c;
    }
};
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> u;
        for(int i=0;i<inorder.size();i++) {
            u[inorder[i]] = i;
        }
        return tree(inorder, postorder, u, postorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* tree(vector<int>& in, vector<int>& p, unordered_map<int, int>&u, int pidx, int ileft, int iright) {
        int rval = p[pidx];
        int irval = u[rval];
        TreeNode* root = new TreeNode(rval);
        if(irval < iright) {
            root->right = tree(in, p, u, pidx-1, irval+1, iright);
        } 
        if(irval>ileft) {
            root->left = tree(in, p, u, pidx+irval-iright-1, ileft, irval-1);
        }
        return root;
    }
};
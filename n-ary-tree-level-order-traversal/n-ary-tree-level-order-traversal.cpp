/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        vector<int>v;
        if(root == nullptr) return {};
        q.push(root);
        q.push(nullptr);
        Node* temp;
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(temp==nullptr) {
                ans.push_back(v);
                v.clear();
                if(q.size())
                    q.push(nullptr);
            } else if(temp!=nullptr) {
                // cout<<temp->val<<endl;
                for(int i = 0;i<temp->children.size();i++) {
                    // if(child!=nullptr)
                    q.push(temp->children[i]);
                }
                v.push_back(temp->val);
            }
        }
        return ans;
    }
};
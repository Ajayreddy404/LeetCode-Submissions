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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        qu.push(root);
        while(!qu.empty()){
            int n = qu.size();
            vector<int> t;
            for(int i=0; i<n; i++){
                TreeNode* node = qu.front();
                t.push_back(node->val);
                qu.pop();
                if(node->left)  qu.push(node->left);
                if(node->right)   qu.push(node->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
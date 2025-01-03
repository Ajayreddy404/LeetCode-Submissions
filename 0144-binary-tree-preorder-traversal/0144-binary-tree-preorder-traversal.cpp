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
    void dfs(TreeNode* node, vector<int> &ans){
        if(node==NULL)  return;
        ans.push_back(node->val);
        if(node->left!=NULL)    dfs(node->left, ans);
        if(node->right!=NULL)   dfs(node->right, ans);
        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // dfs(root, ans);
        // return ans;

        // Morris traversal
        TreeNode* node = root;
        vector<int> arr;
        while(node!=NULL){
            arr.push_back(node->val);
            if(node->left==NULL){
                node = node->right;
                
            }else{
                TreeNode* nd = node->left;
                while(nd->right!=NULL && nd->right!=node){
                    nd = nd->right;
                }

                if(nd->right==NULL){
                    nd->right = node;
                    node = node->left;
                }else{
                    nd->right = NULL;
                    node = node->right;
                    // prev = true;
                    arr.pop_back();
                }
            }
        }
        return arr;
    }
};
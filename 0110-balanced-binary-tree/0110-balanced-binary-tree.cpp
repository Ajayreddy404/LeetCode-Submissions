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

    int dfs(TreeNode* node, bool &flg){
        if(node==NULL)  return 0;
        int lh = dfs(node->left, flg);
        int rh = dfs(node->right, flg);
        if(abs(lh-rh)>1)    flg = false;
        return max(lh,rh)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool flg = true;
        dfs(root, flg);
        return flg;
    }
};
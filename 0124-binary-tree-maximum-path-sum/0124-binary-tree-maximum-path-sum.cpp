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
    // returns the sum of nodes of max-path considering this as root
    int dfs(TreeNode* node, int &maxS){
        if(node==NULL)  return 0;
        int ls = dfs(node->left, maxS);
        int rs = dfs(node->right, maxS);
        int cmax = max(ls, rs) + node->val;
        cmax = max(node->val, cmax);
        maxS = max({maxS, ls + rs + node->val, ls+node->val, rs+node->val, node->val});
        return cmax;
    }

    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        dfs(root, ans);
        return ans;
    }
};
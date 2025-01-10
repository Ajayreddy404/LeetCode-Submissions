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

    int dfs(TreeNode* node, int &maxD){
        if(node==NULL)  return 0;
        int lh = dfs(node->left, maxD);
        int rh = dfs(node->right, maxD);
        maxD = max(1+lh+rh, maxD);
        return max(lh, rh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        dfs(root, maxD);
        return maxD-1;
    }
};
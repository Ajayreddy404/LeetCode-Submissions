/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode* node, int &v1, int &v2, TreeNode* &ans){
        if(node==NULL)  return 0;
        int cnt = 0;
        if(node->val==v1 || node->val==v2)  cnt++;
        int lc = dfs(node->left, v1, v2, ans);
        int rc = dfs(node->right, v1, v2, ans);
        cnt += lc+rc;
        if(ans==NULL && cnt==2)   ans = node;
        return cnt;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        dfs(root, p->val, q->val, ans);
        return ans;
    }
};
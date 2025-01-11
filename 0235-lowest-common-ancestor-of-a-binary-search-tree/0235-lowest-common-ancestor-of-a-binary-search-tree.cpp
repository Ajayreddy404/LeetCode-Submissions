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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p,q);
        // TreeNode* node;
        while(root->val < p->val || root->val > q->val){
            if(root->val < p->val)  root = root->right;
            else if(root->val > q->val) root = root->left;
        }
        return root;
    }
};
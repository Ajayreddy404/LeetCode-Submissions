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
    // returns {minVal, maxVal} in every subtree
    vector<int> checkBST(TreeNode* node, bool &flg){
        // if(node==NULL)  return {INT_MIN, INT_MAX};
        vector<int> lv = {node->val, node->val};
        vector<int> rv = {node->val, node->val};
        if(node->left){
            lv = checkBST(node->left, flg);
            if(lv[1] >= node->val)   flg = false;
        }
        if(node->right){
            rv = checkBST(node->right, flg);
            if(rv[0] <= node->val)   flg = false;
        }
        vector<int> vec = {lv[0], rv[1]};
        return vec;
    }

    bool isValidBST(TreeNode* root) {
        bool flg = true;
        checkBST(root, flg);
        return flg;
    }
};
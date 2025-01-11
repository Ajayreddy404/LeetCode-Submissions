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

    TreeNode* getNode(int l, int r, vector<int> &arr){
        if(l>r) return NULL;
        TreeNode* node = new TreeNode(arr[l]);
        int i = l;
        while(i+1<=r && arr[i+1]<arr[l]){
            i++;
        }
        node->left = getNode(l+1, i, arr);
        node->right = getNode(i+1, r, arr);
        return node;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = getNode(0, preorder.size()-1, preorder);
        return root;
    }
};
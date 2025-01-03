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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        TreeNode* node = root;
        while(node!=NULL){
            if(node->left==NULL){
                arr.push_back(node->val);
                node = node->right;
            }else{
                // find the rightmost node of the left subtree
                TreeNode* nd1 = node->left;
                while(nd1->right!=NULL && nd1->right!=node){
                    nd1 = nd1->right;
                }

                if(nd1->right==node){
                    // link is already present
                    // remove the link and store the node val
                    nd1->right = NULL;
                    arr.push_back(node->val);
                    node = node->right;
                }else{
                    // make a link
                    nd1->right = node;
                    node = node->left;
                }
                
            }
        }
        return arr;
    }
};
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
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        // Morris Traversal
        while(node!=NULL){
            if(node->left==NULL){
                node = node->right;
            }else{
                // getting the right most node in the left subtree of node
                TreeNode* lnode = node->left;
                TreeNode* lrnode = lnode;
                while(lrnode->right!=NULL && lrnode->right!=node){
                    lrnode = lrnode->right;
                }

                if(lrnode->right==NULL){ // no link yet
                    // make link and go to leftnode
                    lrnode->right = node;
                    node = node->left;
                }else{  // link already formed
                    // do transformation and go to right
                    TreeNode* nxtNode = lrnode->right->right;
                    lrnode->right = nxtNode;
                    node->left = NULL;
                    node->right = lnode;
                    node = nxtNode;
                }
            }
        }
        // return root;
    }
};
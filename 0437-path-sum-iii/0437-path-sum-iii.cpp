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

    int ans = 0;

    void rec(TreeNode* node, int targetSum, unordered_map<long,long>& ump, long psum){
        if(node==NULL)  return;
        psum += node->val;
        long req = psum - targetSum;
        if(ump.find(req)!=ump.end()){
            ans += ump[req];
        }
        
        if(ump.find(psum)==ump.end()){
            ump[psum] = 1;
        }else{
            ump[psum]++;
        }

        rec(node->left, targetSum, ump, psum);
        rec(node->right, targetSum, ump, psum);

        if(ump[psum]==1){
            ump.erase(psum);
        }else{
            ump[psum]--;
        }
        
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,long> ump;
        ump[0] = 1;
        rec(root, targetSum, ump, 0L);
        return ans;
    }
};
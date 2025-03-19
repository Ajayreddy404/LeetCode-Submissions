/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int msum = -10000;
    public int rec(TreeNode root){
        if(root==null)  return 0;
        int ls = rec(root.left);
        int rs = rec(root.right);
        int maxSum = root.val;
        maxSum = Math.max(maxSum, Math.max(ls+root.val, rs+root.val));
        msum = Math.max(msum, Math.max(maxSum, ls+rs+root.val));
        return maxSum;
    }
    public int maxPathSum(TreeNode root) {
        rec(root);
        return msum;
    }
}
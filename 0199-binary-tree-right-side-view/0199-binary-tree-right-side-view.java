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
    private void fillArray(List<Integer> lst, TreeNode node, Integer dep){
        if(node==null) return;
        if(lst.size()==dep){
            lst.add(node.val);
        }
        fillArray(lst, node.right, dep+1);
        fillArray(lst, node.left, dep+1);
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> lst = new ArrayList<>();
        fillArray(lst, root, 0);
        return lst;
    }
}
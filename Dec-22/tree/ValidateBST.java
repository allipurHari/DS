https://leetcode.com/problems/validate-binary-search-tree/description/

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
    private TreeNode prev = null;

    private boolean solve(TreeNode root, long mn, long mx){
        if(root == null)
            return true;
        if(root.val >= mx || root.val <= mn)
            return false;
        return solve(root.left, mn, root.val) && solve(root.right, root.val, mx);
    }

    private boolean solve(TreeNode root){
        if(root == null)
            return true;
        if(!solve(root.left))
            return false;
        if(prev != null && root.val <= prev.val)
            return false;
        prev = root;
        return solve(root.right);
    }

    public boolean isValidBST(TreeNode root) {
        // return solve(root, Long.MIN_VALUE, Long.MAX_VALUE);
        return solve(root);
    }
}

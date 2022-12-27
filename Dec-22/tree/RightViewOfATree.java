https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    private List<Integer> result;

    private int getHeight(TreeNode root){
        if(root == null)
            return 0;
        return 1 + Math.max(getHeight(root.left), getHeight(root.right));
    }

    private void solve(TreeNode root, int currHeight){
        if(root == null)    
            return;
        result.set(currHeight, root.val);
        solve(root.left, currHeight+1);
        solve(root.right, currHeight+1);
    }

    public List<Integer> rightSideView(TreeNode root) {
        int h = getHeight(root);
        result = new ArrayList<>(Collections.nCopies(h, 0));
        solve(root, 0);
        return result;
    }
}

https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
    private int result = 0;

    private int solve(TreeNode root){
        if(root == null)
            return 0;
        int l = solve(root.left);
        int r = solve(root.right);
        result = Math.max(result, l+r+1);
        return 1+Math.max(l,r);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        solve(root);
        return (result>0) ? result-1 : result;
    }
}

https://leetcode.com/problems/balanced-binary-tree/

class BalancedBinaryTree {
    private boolean result = true;
    
    private int solve(TreeNode root){
        if(root == null)return 0;
        int l = solve(root.left);
        int r = solve(root.right);
        if(Math.abs(l-r) > 1)
            result = false;
        return 1 + Math.max(l,r);
    }
    
    public boolean isBalanced(TreeNode root) {
        solve(root);
        return result;
    }
}

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

class Solution {
    private int ans = Integer.MIN_VALUE;

    private int solve(TreeNode root){
        if(root == null)
            return 0;
        int l = solve(root.left);
        int r = solve(root.right);
        int rtValue = Math.max(root.val, root.val+Math.max(l,r));
        int mxValue = Math.max(rtValue, root.val+l+r);
        ans = Math.max(ans, mxValue);
        return rtValue;
    }
    public int maxPathSum(TreeNode root) {
        solve(root);
        return ans;
    }
}

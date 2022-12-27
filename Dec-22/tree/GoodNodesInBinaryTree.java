https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

class Solution {
    private int solve(TreeNode root, int mxVal){
        if(root == null)
            return 0;
        mxVal = Math.max(mxVal, root.val);
        int l = solve(root.left, mxVal);
        int r = solve(root.right, mxVal);
        if(root.val < mxVal)
            return l+r;
        return l+r+1;
    }

    public int goodNodes(TreeNode root) {
        return solve(root, Integer.MIN_VALUE);
    }
}

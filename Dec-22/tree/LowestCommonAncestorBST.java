https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

class Solution {
    private TreeNode result = null;

    private void solve(TreeNode root, TreeNode p, TreeNode q){
        if(root == null || result != null)
            return;
        if(p.val < root.val && q.val < root.val)
            solve(root.left, p, q);
        else if(p.val > root.val && q.val > root.val)
            solve(root.right, p, q);
        else
            result = root;    
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        solve(root, p, q);
        return result;
    }
}

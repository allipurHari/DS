https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

class Solution {
    private TreeNode result = null;

    private boolean solve(TreeNode root, TreeNode p, TreeNode q){
        if(root == null){
            if(p == null || q == null)
                return true;
            return false;
        }
        if(result != null)
            return true;
        boolean l = solve(root.left, p, q);
        boolean r = solve(root.right, p, q);
        if(result == null && l && r){
            result = root;
            return true;
        }
        if(result == null && (l || r)){
            if(root.equals(p) || root.equals(q)){
                result = root;
                return true;
            }
        }
        return l || r || root.equals(p) || root.equals(q);
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        solve(root, p, q);
        return result;
    }
}

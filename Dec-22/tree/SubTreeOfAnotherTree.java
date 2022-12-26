https://leetcode.com/problems/subtree-of-another-tree/submissions/

class SubTreeOfAnotherTree {
    private boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)
            return true;
        if(p == null || q == null)
            return false;
        if(isSameTree(p.left, q.left) && isSameTree(p.right, q.right))
            if(p.val == q.val)
                return true;
        return false;
    }
    
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if(root == null)
            return false;
        if(root.val == subRoot.val){
            if(isSameTree(root, subRoot)){
                return true;
            }
        }
        if(isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot))
            return true;
        return false;
    }
}

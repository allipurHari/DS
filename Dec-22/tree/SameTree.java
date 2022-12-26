https://leetcode.com/problems/same-tree/submissions/

class SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)
            return true;
        if(p == null || q == null)
            return false;
        if(isSameTree(p.left, q.left) && isSameTree(p.right, q.right))
            if(p.val == q.val)
                return true;
        return false;
    }
}

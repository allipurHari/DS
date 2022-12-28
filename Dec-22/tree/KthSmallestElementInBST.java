https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

class Solution {
    private Integer result = null;
    private int count = 0;

    private void solve(TreeNode root, int k){
        if(root == null)
            return;
        if(result != null)
            return;
        solve(root.left, k);
        count++;
        if(count == k)
            result = root.val;
        solve(root.right, k);
    }

    public int kthSmallest(TreeNode root, int k) {
        solve(root, k);
        return result;
    }
}

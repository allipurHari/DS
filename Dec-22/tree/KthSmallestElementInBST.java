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
    
    // Iterative approach
    private int solve(TreeNode root, int k){
        Stack<TreeNode> s = new Stack<>();
        while(true){
            while(root != null){
                s.push(root);
                root = root.left;
            }
            root = s.peek();
            s.pop();
            if(--k == 0)
                return root.val;
            root = root.right;
        }
    }

    public int kthSmallest(TreeNode root, int k) {
        solve(root, k);
        return result;
    }
}

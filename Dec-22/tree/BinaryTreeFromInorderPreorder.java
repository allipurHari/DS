https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
    private int preIdx = 0;

    private int getIndex(int[] in, int target, int s, int e){
        for(int i = s; i <= e;i++){
            if(in[i] == target)
                return i;
        }
        return 0;
    }

    private TreeNode solve(int[] pre, int[] in, int s, int e){
        if(s > e)
            return null;
        TreeNode temp = new TreeNode(pre[preIdx]);
        int inIdx = getIndex(in, pre[preIdx], s, e);
        preIdx++;
        temp.left = solve(pre, in, s, inIdx-1);
        temp.right = solve(pre, in, inIdx+1, e);
        return temp;
    }

    public TreeNode buildTree(int[] pre, int[] in) {
        int s = 0, e = pre.length-1;
        return solve(pre, in, s, e);
    }
}

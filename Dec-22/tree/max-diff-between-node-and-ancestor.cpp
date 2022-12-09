https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

class Solution {
public:
    int ans = 0;
    void solve(TreeNode *root, int mn, int mx){
        if(!root)
            return;
        if(mx != INT_MIN){
            ans = max(ans, abs(root->val - mx));
        }
        if(mn != INT_MAX){
            ans = max(ans, abs(root->val - mn));
        }
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        solve(root->left, mn, mx);
        solve(root->right, mn, mx);
    }

    int maxAncestorDiff(TreeNode* root) {
        solve(root, INT_MAX, INT_MIN);
        return ans;
    }
};

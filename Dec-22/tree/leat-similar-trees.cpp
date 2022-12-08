https://leetcode.com/problems/leaf-similar-trees/solutions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void solve(TreeNode *a, vector<int>&v){
    if(!a)
        return;
    if(!a->left && !a->right)
        v.push_back(a->val);
    solve(a->left, v);
    solve(a->right, v);
}

class Solution {
public:
    bool leafSimilar(TreeNode* a, TreeNode* b) {
        vector<int> av, bv;
        solve(a, av);
        solve(b, bv);
        return av == bv;
    }
};

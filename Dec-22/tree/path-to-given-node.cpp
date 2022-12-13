https://www.interviewbit.com/old/problems/path-to-given-node/

bool solve1(TreeNode* A, int B, vector<int>&ans){
    if(!A)return false;
    ans.push_back(A->val);
    if(A->val == B)
        return true;
    if(solve1(A->left, B, ans) || solve1(A->right, B, ans))
        return true;
    ans.pop_back();
    return false;
} 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    solve1(A, B, ans);
    return ans;
}

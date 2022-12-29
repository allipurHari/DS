https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void solve(vector<int> c, vector<int> &v, int idx, int sum, vector<vector<int>> &ans){
        if(sum == 0){
            ans.push_back(v);
            return;
        }
        if(idx == c.size())
            return;
        if(c[idx] <= sum){
            v.push_back(c[idx]);
            solve(c, v, idx, sum-c[idx], ans);
            v.pop_back();
        }
        solve(c, v, idx+1, sum, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(c, v, 0, target, ans);
        return ans;
    }
};

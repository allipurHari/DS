https://leetcode.com/problems/longest-increasing-subsequence/description/

// Memoization
class Solution {
public:
    int solve(int idx, int pre, vector<int>v, vector<vector<int> >&dp){
        if(idx < 0)
            return 0;
        if(dp[idx][pre-1] != -1)
            return dp[idx][pre-1];
        int pick = 0;
        if(pre == v.size() || v[idx] < v[pre])
            pick = 1 + solve(idx-1, idx, v, dp);
        int noPick = solve(idx-1, pre, v, dp);
        return dp[idx][pre-1] = max(pick ,noPick);
    }

    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int> >dp(n, vector<int>(n, -1));
        return solve(n-1, n, v, dp);
    }
};

//Tabulation
int lengthOfLIS(vector<int>& v) {
    int n = v.size();
    vector<vector<int> >dp(n+1, vector<int>(n+1, 0));
    for(int i = 1;i <= n;i++){
        for(int pre = i+1; pre <= n+1;pre++){
            int noPick = dp[i-1][pre-1];
            int pick = 0;
            if(pre == n+1 || v[i-1] < v[pre-1])
                pick = 1+dp[i-1][i-1];
            dp[i][pre-1] = max(pick, noPick);
        }
    }
    return dp[n][n];
}

// Optimal solution
class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        if(!n)return 0;
        vector<int>res;
        res.push_back(v[0]);
        for(int i = 1;i < v.size();i++){
            if(v[i] > res[res.size()-1])
                res.push_back(v[i]);
            else{
                int idx = lower_bound(res.begin(), res.end(), v[i])-res.begin();
                res[idx] = v[i];
            }
        }
        return res.size();
    }
};

https://leetcode.com/problems/longest-common-subsequence/submissions/

class Solution {
public:
  
    // Memoization
    int solve(int i, int j, string a, string b, vector<vector<int>>&dp){
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int pick = 0;
        if(a[i] == b[j])
            pick = 1 + solve(i-1, j-1, a, b, dp);
        int noPick = max(solve(i-1, j, a, b, dp), solve(i, j-1, a, b, dp));
        return dp[i][j] = max(pick, noPick);
    }

    // Tabulation
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        // return solve(s1.size()-1, s2.size()-1, s1, s2, dp);
        for(int i = 1;i <= s1.size();i++){
            for(int j = 1;j <= s2.size();j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

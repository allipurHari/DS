https://leetcode.com/problems/house-robber/

// Had to be cautious about return statement

class Solution {
public:

    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1)
            return a[0];
        if(n == 2)
            return max(a[0], a[1]);
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = a[0];
        dp[2] = a[1];
        for(int i = 3;i <= n;i++){
            dp[i] = a[i-1] + max(dp[i-2], dp[i-3]);
        }
        return max(dp[n], dp[n-1]);
    }
};

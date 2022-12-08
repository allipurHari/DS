https://bit.ly/3FvHbMO

int solve(int i, int w, vector<int>vv, vector<int> wv, vector<vector<int>>&dp){
    if(w == 0 || i >= vv.size())
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    int pick = 0;
    if(vv[i] <= w){
        pick = wv[i] + solve(i+1, w-vv[i], vv, wv, dp);
    }
    int noPick = solve(i+1, w, vv, wv, dp);
    return dp[i][w] = max(pick, noPick);
}

int maxProfit(vector<int> &vv, vector<int> &wv, int n, int w)
{
	// Write your code here
    vector<vector<int>>dp(n, vector<int>(w+1, -1));
    return solve(0, w, wv, vv, dp);
}

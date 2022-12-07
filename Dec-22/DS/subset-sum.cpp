https://www.interviewbit.com/problems/subset-sum-problem/hints/

int Solution::solve(vector<int> &A, int B) {
    vector<vector<bool>> dp(A.size()+1, vector<bool>(B+1, false));
    for(int i = 0;i <= A.size();i++){
        dp[i][0] = true;
    }
    for(int i = 1;i <= A.size();i++){
        for(int j = 1;j <= B;j++){
            int pick = false;
            if(A[i-1] <= j){
                pick = dp[i-1][j-A[i-1]];
            }
            int noPick = dp[i-1][j];
            dp[i][j] = pick || noPick;
        }
    }
    return dp[A.size()][B];
}

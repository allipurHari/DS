https://leetcode.com/problems/partition-equal-subset-sum/

// Had to be careful with initializing the size of the dynamic array, improper initializing lead to stackoverflow

class Solution {
public:
    
    // Memoization
    
    // bool subset(int idx, int sum, vector<int> nums, vector<vector<int>> &dp) {
        // if(idx < 0)
        //     return false;
        // else if(nums[idx] == sum){
        //     dp[idx][sum] = 1;
        //     return true;
        // }
        // else if(dp[idx][sum] != -1){
        //     return dp[idx][sum];
        // }
        // else if(nums[idx] > sum){
        //     dp[idx][sum] = subset(idx-1, sum, nums, dp);
        // }
        // else{
        //     dp[idx][sum] = subset(idx-1, sum-nums[idx], nums, dp) || subset(idx-1, sum, nums, dp);
        // }
        // return dp[idx][sum];
    // }
    
    // Top down
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)
            return false;
        sum = sum/2;
        vector<vector<bool>>dp(nums.size()+1, vector<bool>(sum+1, false));
        // return subset(nums.size()-1, sum, nums, dp);
        for(int i = 0; i <= nums.size(); i++)
            dp[i][0] = true;
        for(int i = 1;i <= nums.size();i++){
            for(int j = 1;j <= sum;j++){
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
        }
        return dp[nums.size()][sum];
    }
};

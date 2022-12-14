https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(!n)true;
        int mx = 0, i = 0;
        while(i <= mx && mx < n-1){
            mx = max(nums[i]+i, mx);
            i++;
        }
        if(mx >= n-1)
            return true;
        return false;
    }
};

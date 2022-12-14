https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)return 0;
        int i = 1, mxe = nums[0], mx = nums[0];
        int ans = 1;
        while(mxe < n-1){
            mx = max(mx, nums[i]+i);
            if(mxe == i){
                ans++;
                mxe = mx;
            }
            i++;
        }
        return ans;
    }
};

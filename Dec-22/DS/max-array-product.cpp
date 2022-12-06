https://leetcode.com/problems/maximum-product-subarray/discussion/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
        return 0;
        int mxSum = 1;
        int mnSum = 1;
        int ans = nums[0];
        for(int i = 0;i < nums.size();i++){
            if(nums[i] < 0)
                swap(mxSum, mnSum);
            mxSum = max(mxSum*nums[i], nums[i]);
            mnSum = min(mnSum*nums[i], nums[i]);
            ans = max(ans, mxSum);
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};

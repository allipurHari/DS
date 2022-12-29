https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>nums, vector<int>&v, int idx){
        if(idx == nums.size()){
            ans.push_back(v);
            return;
        }
        solve(nums, v, idx+1);
        v.push_back(nums[idx]);
        solve(nums, v, idx+1);
        v.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        solve(nums, v, 0);
        return ans;
    }
};

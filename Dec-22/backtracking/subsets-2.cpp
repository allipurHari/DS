class Solution {
public:
    void solve(vector<int>nums, vector<int>&v, int idx, set<vector<int>>&s){
        if(idx == nums.size()){
            s.insert(v);
            return;
        }
        solve(nums, v, idx+1, s);
        v.push_back(nums[idx]);
        solve(nums, v, idx+1, s);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int>v;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, v, 0, s);
        for(auto i : s)
            ans.push_back(i);
        return ans;
    }
};

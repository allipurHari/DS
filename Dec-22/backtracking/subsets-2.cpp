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
    
    // Iterative
        vector<vector<int>> solve(vector<int> nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {{}};
        if(!nums.size())return ans;
        ans.push_back(vector<int>(1, nums[0]));
        int startIdx = 1;
        for(int i = 1;i < nums.size();i++){
            int j = 0;
            if(nums[i] == nums[i-1]){
                j = startIdx;
            }
            if(i == nums.size())
                break;
            int s = ans.size();
            int count = 0;
            for(;j < s;j++){
                vector<int>temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
                count++;
            }
            startIdx = ans.size()-count;
        }
        return ans;
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

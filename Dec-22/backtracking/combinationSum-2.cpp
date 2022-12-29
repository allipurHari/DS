https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
     void solve(vector<int> c, vector<int> &v, int idx, int sum, vector<vector<int>> &ans, unordered_map<int, int> &mp){
        if(sum == 0){
            ans.push_back(v);
            return;
        }
        if(idx == c.size())
            return;

        if(c[idx] <= sum && mp[c[idx]]){
            v.push_back(c[idx]);
            mp[c[idx]]--;
            solve(c, v, idx, sum-c[idx], ans, mp);
            mp[c[idx]]++;
            v.pop_back();
        }
        solve(c, v, idx+1, sum, ans, mp);
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        unordered_set<int>s;
        unordered_map<int, int>mp;
        for(auto i : c){
            mp[i]++;
            s.insert(i);
        }
        vector<int>t;
        for(auto &i : s){
            t.push_back(i);
        }
        solve(t, v, 0, target, ans, mp);
        return ans;
    }
};

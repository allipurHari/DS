https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        int i = 0, n = v.size(), mn, mx;
        while(i < n){
            mn = v[i][0];
            mx = v[i][1];
            for(i = i+1;i < n;i++){
                if(v[i][0] <= mx){
                    mx = max(mx, v[i][1]);
                }else{
                    res.push_back(vector<int>{mn, mx});
                    break;
                }
            }
        }
        if(i == n){
            res.push_back(vector<int>{mn, mx});
        }
        return res;
    }
};

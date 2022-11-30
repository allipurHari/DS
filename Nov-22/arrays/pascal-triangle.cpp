https://leetcode.com/problems/pascals-triangle/

// Did it in a go

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.push_back(vector<int>(1,1));
        if(n == 1)
            return res;
        res.push_back(vector<int>(2,1));
        if(n == 2)
            return res;
        
        vector<int>pre = res[1];
        for(int i = 2;i < n;i++){
            vector<int>v(i+1, 1);
            for(int j = 1;j < i;j++){
                v[j] = pre[j-1] + pre[j];
            }
            res.push_back(v);
            pre = v;
        }
        return res;
    }
};

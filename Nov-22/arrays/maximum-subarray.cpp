https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int mxs = INT_MIN, sum = 0;
        for(auto i : v){
            if(i+sum > i)
                sum = i+sum;
            else
                sum = i;
            mxs = max(mxs, sum);
        }
        return mxs;
    }
};

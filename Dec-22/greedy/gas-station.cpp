https://leetcode.com/problems/gas-station/description/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>v(n);
        int aggr = 0;
        for(int i =0;i < n;i++){
            v[i] = gas[i]-cost[i];
            aggr += v[i];
        }
        if(aggr < 0)return -1;
        int mxs = INT_MIN, sum = 0, idx = 0, tempidx = 0;
        for(int i = 0;i < n;i++){
            if(v[i]+sum > v[i])
                sum = v[i]+sum;
            else{
                sum = v[i];
                tempidx = i;
            }
            if(mxs < sum){
                idx = tempidx;
                mxs = sum;
            }
        }
        int cond = tempidx;
        for(int i = 0; i < cond;i++){
            if(v[i]+sum > v[i])
                sum = v[i]+sum;
            else{
                sum = v[i];
                tempidx = i;
            }
            if(mxs < sum){
                idx = tempidx;
                mxs = sum;
            }
        }
        return idx;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// A silly mistake, a bit cautious this time to avoid such but better

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if(n == 0)
            return 0;
        int sum = 0;
        int mx = p[n-1];
        for(int i = n-2;i >= 0;i--){
            if(p[i] > mx)
                mx = p[i];
            else
                sum = max(sum, mx - p[i]);
        }
        return sum;
    }
};

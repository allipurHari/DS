https://leetcode.com/problems/min-cost-climbing-stairs/submissions/

// Took more than 50 minutes, memorization thrown TLE so had to do it in top-down

class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int one = 0, two = 0, n = a.size();
        for(int i = 2;i <= n;i++){
            int temp = one;
            one = min(a[i-1] + one, a[i-2] + two);
            two = temp;
        }
        return one;
    }
};

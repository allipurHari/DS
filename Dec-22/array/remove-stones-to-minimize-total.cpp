https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        int ans = 0;
        for(auto i : piles)
            q.push(i);
        while(k--){
            float top = q.top();
            q.pop();
            q.push(ceil(top/2));
        }
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};

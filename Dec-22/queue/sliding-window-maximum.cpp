https://leetcode.com/problems/sliding-window-maximum/submissions/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();
        deque<int>q;
        vector<int>res(n-k+1);
        for(int i = 0;i < k;i++){
            while(!q.empty() && v[i] > q.back())
                q.pop_back();
            q.push_back(v[i]);
        }
        res[0] = q.front();
        for(int i = k;i < n;i++){
            if(q.front() == v[i-k])
                q.pop_front();
            while(!q.empty() && v[i] > q.back())
                q.pop_back();
            q.push_back(v[i]);
            res[i-k+1] = q.front();
        }
        return res;
    }
};

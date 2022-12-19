https://leetcode.com/problems/k-closest-points-to-origin/submissions/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        priority_queue<pair<double, int> > pq;
        for(int i = 0;i < v.size();i++){
            pq.push({sqrt(v[i][0]*v[i][0] + v[i][1]*v[i][1]), i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(v[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};

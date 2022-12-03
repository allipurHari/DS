https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/

class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        vector<int>r(n), l(n);
        stack<int>s;
        int mx = 0;
        for(int i = n-1;i >= 0;i--){
            while(!s.empty() && v[i] <= v[s.top()]){
                s.pop();
            }
            r[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i = 0;i < n;i++){
            while(!s.empty() && v[i] <= v[s.top()]){
                s.pop();
            }
            l[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        for(int i = 0;i < n;i++){
            int count = 0;
            if(r[i] == -1){
                count += n - 1 - i;
            }
            else{
                count += r[i] - i -1;
            }
            if(l[i] == -1){
                count += i - 0;
            }
            else{
                count += i - l[i] - 1;
            }
            mx = max(mx, (count + 1)*v[i]);
        }
        return mx;
    }
};

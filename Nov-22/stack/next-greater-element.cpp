https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        stack<int> s;
        vector<int> res(n);
        for(int i = n-2;i >= 0;i--){
            while(!s.empty() && v[i] > s.top()){
                s.pop();
            }
            s.push(v[i]);
        }
        for(int i = n-1;i >= 0;i--){
            while(!s.empty() && s.top() <= v[i]){
                s.pop();
            }
            res[i] = (!s.empty()) ? s.top() : -1;
            s.push(v[i]);
        }
        return res;
    }
};

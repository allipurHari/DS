https://leetcode.com/problems/find-the-duplicate-number/solution/

class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size();
        for(int i = 0;i < n;i++){
            int idx = (v[i] > n) ? v[i]-n-1 : v[i]-1;
            if(v[idx] > n){
                return idx+1;
            }
            else{
                v[idx] += n;
            }
        }
        return 0;
    }
};

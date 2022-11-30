// https://leetcode.com/problems/sort-colors/submissions/

class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size(), iz = 0, it = n-1;
        for(int i = 0;i < n;i++){
            if(v[i] == 0)
                swap(v[iz++], v[i]);
        }
        for(int i = n-1;i >= iz;i--){
            if(v[i] == 2)
                swap(v[it--], v[i]);
        }
    }
};

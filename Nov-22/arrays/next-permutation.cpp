https://leetcode.com/problems/next-permutation/submissions/

// Should have broken the problem into which number to swap and to where then I would have cracked it.

class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size(), k = n-2;
        for(;k>=0;k--){
            if(v[k] < v[k+1])
                break;
        }
        if(k < 0)
            reverse(v.begin(), v.end());
        else{
            int l = n-1;
            for(;l > k;l--){
                if(v[l] > v[k])
                    break;
            }
            swap(v[l], v[k]);
            reverse(v.begin()+k+1, v.end());
        }
    }
};

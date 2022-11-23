https://leetcode.com/problems/container-with-most-water/submissions/

// Did it in a go

class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int i = 0, j = n-1, max_sum = 0;
        while(i < j){
            max_sum = max(max_sum, min(a[j], a[i])*(j-i));
            if(a[i] < a[j])
                i++;
            else
                j--;
        }
        return max_sum;
    }
};

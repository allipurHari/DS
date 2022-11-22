https://www.interviewbit.com/old/problems/counting-triangles/

// I failed in the logic implementation.

int Solution::nTriang(vector<int> &a) {
    int n = a.size(), count = 0, i, j, sum;
    int mod = 1000000007;
    sort(a.begin(), a.end());
    for(int k = n-1;k >= 1;k--){
        i = 0, j = k-1;
        while(i < j){
            sum = a[i] + a[j];
            if(sum > a[k]){
                count+=j-i;
                j--;
            }
            else
                i++;
        }
        count %= mod;
    }
    return count;
}

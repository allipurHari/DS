https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/hints/

// Done in one go

void Solution::merge(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    vector<int> tmp(n+m);
    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if(a[i] < b[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = b[j++];
    }
    while(i < n){
        tmp[k++] = a[i++];
    }
    while(j < m)
        tmp[k++] = b[j++];
    a = tmp;
}

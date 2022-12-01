https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &v) {
    int n = v.size(), sum = 0;
    long long sqsum = 0;
    for(int i = 0;i < n;i++){
        sum += v[i];
        sum -= i+1;
        sqsum += (long long)v[i]* (long long)v[i];
        sqsum -= (long long)(i+1) * (long long)(i+1);
    }
    long long apb = sqsum/sum;
    int a = ((int)apb + sum)/2;
    int b = int(a - sum);
    return vector<int>{a, b};
}

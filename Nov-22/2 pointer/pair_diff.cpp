https://www.interviewbit.com/problems/pair-with-given-difference/

// I was successful at the 4th time submissioin, reasons being missing few test cases.
// Improper handling of negative number etc. So, before submission try out the various test cases. 
// Better the test cases better the code

int Solution::solve(vector<int> &a, int B) {
    sort(a.begin(), a.end());
    int i = 0, j = 1, diff;
    B = abs(B);
    while(j < a.size()){
        diff = a[j] - a[i];
        if(i != j && diff == B)
            return 1;
        else if(diff <= B)
            j++;
        else
            i++;
    }
    return 0;
}

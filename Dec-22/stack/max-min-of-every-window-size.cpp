https://bit.ly/3zUYLZz

#include <bits/stdc++.h> 

vector<int> previousSmaller(vector<int> &arr, int n) 
{
    vector<int> prev(n);
    stack<int> s;

    for (int i = 0; i < n; i++) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        
        if (s.empty()) 
        {
            prev[i] = -1;
        } 
        else 
        {
            prev[i] = s.top();
        }

        s.push(i);
    }
    
    return prev;
}

// This function will return an array.
// Each ith position contains the index of next smaller elements in the original array.
vector<int> nextSmaller(vector<int> &arr, int n) 
{
    stack<int> s;
    vector<int> next(n);

    for (int i = n - 1; i >= 0; i--) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        
        if (s.empty()) 
        {
            next[i] = n;
        } 
        else 
        {
            next[i] = s.top();
        }
    
        s.push(i);
    }
    
    return next;
}


vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> left = previousSmaller(a, n);
    vector<int> right = nextSmaller(a,n);
    vector<int> ans(n, INT_MIN);
    for(int i = 0;i < n;i++){
        int ws = right[i] - left[i] - 1;
        ans[ws-1] = max(ans[ws-1], a[i]);
    }
    for(int i = n-2; i >= 0;i--){
        ans[i] = max(ans[i], ans[i+1]);
    }
    return ans;
}

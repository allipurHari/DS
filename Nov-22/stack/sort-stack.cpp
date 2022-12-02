https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h> 

void solve(int &mn, int n, bool &flag, stack<int>&s){
    if(n == 0){
        s.push(mn);
        return;
    }
    int top = s.top();
    s.pop();
    mn = min(mn, top);
    solve(mn, n-1, flag, s);
    if(top != mn || flag == true){
        s.push(top);
    }
    else{
        flag = true;
    }
}

void sortStack(stack<int> &s)
{
	// Write your code here
    int n = s.size(), mn;
    for(int i = n;i > 0;i--){
        mn = INT_MAX;
        bool flag = false;
        solve(mn, i, flag, s);
    }
}

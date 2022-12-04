https://bit.ly/3GuImxi

#include <bits/stdc++.h> 
int findCelebrity(int n) {
 	// Write your code here.
    stack<int>s;
    for(int i = 0;i < n;i++){
        s.push(i);
    }
    while(s.size() != 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(a,b))
            s.push(b);
        else
            s.push(a);
    }
    for(int i = 0;i < n;i++){
        if(i != s.top() && knows(s.top(), i))
            return -1;
    }
    
    for(int i = 0;i < n;i++){
        if(i != s.top() && !knows(i, s.top()))
            return -1;
    }
    return s.top();
}

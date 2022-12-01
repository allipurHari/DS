https://bit.ly/3KbIjIW

#include <bits/stdc++.h> 
class Queue {
public:
    vector<int>v;
    const int cap = 1000;
    int curr;
    Queue() {
        // Implement the Constructor
        v.resize(cap);
        curr = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(curr == -1)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(curr != cap-1)
            v[++curr] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(!isEmpty()){
            int temp = v[0];
            for(int i = 0;i < curr;i++){
                v[i] = v[i+1];
            }
            curr--;
            return temp;
        }
        return -1;
    }

    int front() {
        // Implement the front() function
        if(curr != -1)
            return v[0];
        else
            return -1;
    }
};

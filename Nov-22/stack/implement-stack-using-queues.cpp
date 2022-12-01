https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> q1, q2;
    int currq;
    MyStack() {
        currq = 1;
    }
    
    void push(int x) {
        if(currq == 1)
            q1.push(x);
        else
            q2.push(x);
    }
    
    int pop() {
        if(currq == 1 && !q1.empty()){
            int front = q1.front();
            q1.pop();
            while(!q1.empty()){
                q2.push(front);
                front = q1.front();
                q1.pop();
            }
            currq = 2;
            return front;
        }
        else if(currq == 2 && !q2.empty()){
            int front = q2.front();
            q2.pop();
            while(!q2.empty()){
                q1.push(front);
                front = q2.front();
                q2.pop();
            }
            currq = 1;
            return front;
        }
        return -1;
    }
    
    int top() {
        int top = pop();
        push(top);
        return top;
    }
    
    bool empty() {
        if(currq == 1)
            return q1.empty();
        return q2.empty();
    }
};

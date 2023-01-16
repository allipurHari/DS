https://leetcode.com/problems/min-stack/description/

class MinStack {
    LinkedList<Integer> list;
    int mn;
    public MinStack() {
        list = new LinkedList<>();
        mn = Integer.MAX_VALUE;
    }
    
    public void push(int val) {
        if(mn >= val){
            list.add(mn);
            mn = val;
        }
        list.add(val);
    }
    
    public void pop() {
        if(top() == mn){
            list.removeLast();
            mn = list.pollLast();
        }
        else
            list.removeLast();
    }
    
    public int top() {
        return list.peekLast();
    }
    
    public int getMin() {
        return mn;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

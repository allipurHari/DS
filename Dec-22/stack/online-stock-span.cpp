https://leetcode.com/problems/online-stock-span/submissions/

class StockSpanner {
public:
    stack<pair<int, int> >s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!s.empty() && price >= s.top().first){
            ans += s.top().second;
            s.pop();
        }
        s.push({price, ans});
        return ans;
    }
};

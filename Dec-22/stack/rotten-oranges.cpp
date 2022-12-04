https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int n = v.size();
        if(n==0)return -1;
        int m = v[0].size();
        int go = 0;
        stack<pair<int, int> >s;
        for(int i= 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(v[i][j] == 1)
                    go++;
                else if(v[i][j] == 2)
                    s.push({i,j});
            }
        }
        int time = 0;
        stack<pair<int, int> >temp;
        while(!s.empty()){
            int i = s.top().first;
            int j = s.top().second;
            if(i != n-1 && v[i+1][j] == 1){
                temp.push({i+1,j});
                v[i+1][j] = 2;
                go--;
            }
            if(i != 0 && v[i-1][j] == 1){
                temp.push({i-1,j});
                v[i-1][j] = 2;
                go--;
            }
            if(j != m-1 && v[i][j+1] == 1){
                temp.push({i,j+1});
                v[i][j+1] = 2;
                go--;
            }
            if(j != 0 && v[i][j-1] == 1){
                temp.push({i,j-1});
                v[i][j-1] = 2;
                go--;
            }
            s.pop();
            if(s.empty()){
                if(temp.empty()){
                    return go ? -1 : time;
                }
                while(!temp.empty()){
                    s.push(temp.top());
                    temp.pop();
                }
                time++;
            }
        }
        return go ? -1 : time;
    }
};

https://leetcode.com/problems/rotate-image/submissions/

// A blunder, missed a loop. I knew the case but I was over confident

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int count;
        if(!m.size())
            return;
        int i,j, di, dj;
        for(i = 0;i < m.size()/2;i++){
            for(j = i;j < m.size()-i-1;j++){
                count = 0;
                int update = m[i][j];
                while(count < 4){
                    di = j;
                    dj = m.size()-i-1;
                    int temp = m[di][dj];
                    m[di][dj] = update;
                    update = temp;
                    i = di, j = dj;
                    count++;
                }
            }
        }
    }
};

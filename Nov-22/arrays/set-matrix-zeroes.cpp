https://leetcode.com/problems/set-matrix-zeroes/submissions/

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int rs = m.size();
        if(!rs)
            return;
        int cs = m[0].size();
        vector<int>r(rs, 0), c(cs, 0);
        for(int i = 0; i < rs;i++){
            for(int j = 0;j < cs;j++){
                if(m[i][j] == 0){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < rs;i++){
            for(int j = 0;j < cs;j++){
                if(r[i] == 1 || c[j] == 1){
                    m[i][j] = 0;
                }
            }
        }
    }
};

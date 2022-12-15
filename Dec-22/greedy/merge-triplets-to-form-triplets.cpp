https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& v, vector<int>& target) {
        int n= v.size();
        unordered_set<int>s;
        int a = target[0], b = target[1], c = target[2];
        for(int i = 0;i < n;i++){
            if(v[i][0] <= a && v[i][1] <= b && v[i][2] <= c)
                s.insert(i);
        }
        if(!s.size())return false;
        int counta = 0, countb = 0, countc = 0;
        for(int i = 0;i < n;i++){
            if(v[i][0] == a){
                if(s.find(i) != s.end())
                    counta++;
            }
            if(v[i][1] == b){
                if(s.find(i) != s.end())
                    countb++;
            }
            if(v[i][2] == c){
                if(s.find(i) != s.end())
                    countc++;
            }
        }
        if(counta && countb && countc)
            return true;
        return false;
    }
};

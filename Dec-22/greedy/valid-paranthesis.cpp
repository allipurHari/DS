https://leetcode.com/problems/valid-parenthesis-string/description/

class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for(auto i : s){
            if(i == '('){
                cmax++;
                cmin++;
            }
            else if(i == '*'){
                cmax++;
                cmin--;
            }
            else{
                cmax--;
                cmin--;
            }
            if(cmax < 0)return false;
            cmin = max(cmin, 0);
        }
        return cmin == 0;
    }
};

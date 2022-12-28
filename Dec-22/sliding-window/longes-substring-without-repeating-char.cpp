class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> v(256, false);
        int ans = 0, i =0;
        for(int j = 0;j < s.size();j++){
            if(v[s[j]]){
                while(s[i] != s[j]){
                    v[s[i]] = false;
                    i++;
                }
                i++;
            }
            else{
                v[s[j]] = true;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

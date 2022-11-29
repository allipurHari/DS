https://leetcode.com/problems/reverse-words-in-a-string/

// Silly mistake

class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string str="";
        for(auto i: s){
            if(i != ' ')
                str+=i;
            else{
                if(str != "")
                    v.push_back(str);
                str="";
            }
        }
        if(str != "")
            v.push_back(str);
        reverse(v.begin(), v.end());
        string res="";
        for(auto i : v){
            res += i + " ";
        }
        return res.size() ? res.substr(0, res.size()-1) : "";
    }
};

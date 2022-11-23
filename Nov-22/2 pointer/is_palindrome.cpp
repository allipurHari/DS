https://leetcode.com/problems/valid-palindrome/submissions/

// Did it one go

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else if(tolower(s[i]) == tolower(s[j])){
                i++;j--;
            }   
            else
                return 0;
        }
        return 1;
    }
};

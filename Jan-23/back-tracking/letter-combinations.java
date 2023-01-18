https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
    HashMap<Character, String> mp = new HashMap<>();
    List<String> ans = new ArrayList<>();

    Solution(){
        mp.put('2',"abc");
        mp.put('3',"def");
        mp.put('4',"ghi");
        mp.put('5',"jkl");
        mp.put('6',"mno");
        mp.put('7',"pqrs");
        mp.put('8',"tuv");
        mp.put('9',"wxyz");
    }

    private void solve(int idx, String digits, StringBuilder s){
        if(idx == digits.length()){
            ans.add(s.toString());
            return;
        }
        String temp = mp.get(digits.charAt(idx));
        for(char j : temp.toCharArray()){
            s.append(j);
            solve(idx+1, digits, s);
            s.deleteCharAt(s.length()-1);
        }
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0)
            return ans;
        solve(0, digits, new StringBuilder());
        return ans;
    }
}

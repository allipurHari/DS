https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
    public String convert(String s, int numRows) {
        List<StringBuilder> list = new ArrayList<>();
        for(int i = 0;i < numRows;i++){
            list.add(new StringBuilder());
        }
        int n = s.length();
        if(numRows == 1)
            return s;
        int idx = 0;
        boolean flag = true;
        for(int i = 0;i < n;i++){
            if(idx == numRows-1){
                flag = false;
            }
            else if(idx == 0){
                flag = true;
            }
            list.get(idx).append(s.charAt(i));
            idx = flag ? ++idx : --idx;
        }
        StringBuilder ans = new StringBuilder();
        for(StringBuilder sb : list){
            ans.append(sb.toString());
        }
        return ans.toString();
    }
}

https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
    public int longestConsecutive(int[] nums) {
        int result = 0;
        HashSet<Integer> set = new HashSet<Integer>();
        for(int num : nums)
            set.add(num);
        for(int num : nums){
            if(!set.contains(num-1)){
                int count = 0;
                int temp = num;
                while(set.contains(temp)){
                    count++;
                    temp++;
                }
                result = Math.max(result, count);
            }
        }
        return result;
    }
}

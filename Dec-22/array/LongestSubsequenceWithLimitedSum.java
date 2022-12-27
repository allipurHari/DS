https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

class Solution {
    private int getCount(int[] a, int target){
        int s = 0, e = a.length-1;
        int mid = s + (e-s)/2;
        while(s+1 < e){
            mid = s + (e-s+1)/2;
            if(a[mid] == target)
                return mid+1;
            else if(a[mid] > target)
                e = mid;
            else
                s = mid;
        }
        if(target < a[s])return s;
        if(target >= a[e])return e+1;
        else return s+1;
    }

    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int[] result = new int[queries.length];
        for(int i = 1;i < nums.length;i++){
            nums[i] += nums[i-1];
        }
        for(int i = 0;i < queries.length;i++){
            result[i] = getCount(nums, queries[i]);
        }
        return result;
    }
}

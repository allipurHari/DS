https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
    private int findSmallest(int[] nums){
        int s = 0, e = nums.length-1;
        int mid;
        while(s < e){
            mid = s + (e-s)/2;
            if(mid-1 >= 0 && nums[mid-1] > nums[mid] && nums[mid-1] > nums[nums.length-1])
                return mid;
            else if(mid+1 < nums.length-1 && nums[mid] > nums[mid+1] && nums[mid] > nums[nums.length-1])
                return mid+1;
            if(nums[mid] > nums[nums.length-1])
                s = mid+1;
            else
                e = mid-1;
        }
        return s+(e-s)/2;
    }

    private int search(int[] nums, int s, int e, int target) {
        int mid;
        while(s <= e){
            mid = s + (e-s)/2;
            int midValue = nums[mid];
            if(midValue == target)
                return mid;
            if(target > midValue)
                s = mid+1;
            else
                e = mid-1;
        }
        return -1;
    }

    public int search(int[] nums, int target) {
        int smallIndex = findSmallest(nums);
        int l = 0, h = nums.length-1;
        if(target == nums[smallIndex])
            return smallIndex;
        if(target > nums[smallIndex]){
            if(target <= nums[nums.length-1])
                l = smallIndex+1;
            else 
                h = smallIndex-1;
        }
        else if(target < nums[smallIndex])
            return -1;
        return search(nums, l, h, target);
    }
}

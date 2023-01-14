https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {

    private boolean canEat(int[] piles, int h, int val){
        int i = 0, count = 0;
        if(piles.length == 0)
            return true;
        while(i < piles.length){
            count += Math.ceil((double)piles[i]/val);
            i++;
            if(count > h)
                return false;
        }
        return true;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int e = 0,s;
        int n = piles.length;
        for(int i = 0;i < n;i++){
            e = Math.max(e, piles[i]);
        }
        s = 1;
        int mid, ans = e;
        while(s <= e){
            mid = s + (e-s)/2;
            if(canEat(piles, h, mid)){
                ans = Math.min(ans, mid);
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
}

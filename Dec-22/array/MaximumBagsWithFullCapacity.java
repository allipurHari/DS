https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

class Solution {
    public int maximumBags(int[] c, int[] r, int ar) {
        int size = c.length;
        int[] rc = new int[size];
        for(int i = 0;i < size;i++){
            rc[i] = c[i]-r[i];
        }
        Arrays.sort(rc);
        int ans = 0;
        for(int i = 0;i < size && ar-rc[i] >= 0;i++){
            ans++;
            ar -= rc[i];
        }
        return ans;
    }
}

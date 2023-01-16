https://leetcode.com/problems/number-of-islands/description/

class Solution {
    private void solve(char[][] grid, int i, int j, int n, int m){
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        solve(grid, i-1, j, n, m);
        solve(grid, i+1, j, n, m);
        solve(grid, i, j-1, n, m);
        solve(grid, i, j+1, n, m);
    }

    public int numIslands(char[][] grid) {
        int n = grid.length;
        if(n == 0)
            return 0;
        int m = grid[0].length, ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == '1'){
                    solve(grid, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
}

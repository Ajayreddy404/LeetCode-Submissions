class Solution {
    int n,m;
    public void mark(int i, int j, char[][] grid, boolean[][] vis){
        if(i>=n || i<0 || j>=m || j<0) return;
        if(vis[i][j] || grid[i][j]=='0') return;
        vis[i][j] = true;
        mark(i+1, j, grid, vis);
        mark(i, j+1, grid, vis);
        mark(i-1, j, grid, vis);
        mark(i, j-1, grid, vis);
    }

    public int numIslands(char[][] grid) {
        n = grid.length;
        m = grid[0].length;
        int cnt = 0;
        boolean[][] vis = new boolean[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    mark(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
}
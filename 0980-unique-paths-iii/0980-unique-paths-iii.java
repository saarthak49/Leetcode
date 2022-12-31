class Solution {
    
    
    private int[] x = {1, -1, 0, 0};
    private int[] y = {0, 0, 1, -1};
    
    public boolean valid(int m, int n, int i, int j)
    {
        if(i>=0 && i<=m-1 && j >= 0 && j<=n-1)
            return true;
        return false;
    }
    private static int counter;
    public void count(int[][] grid, int m, int n, int si, int sj, boolean[][] vis, int c)
    {
        if(grid[si][sj] == 2)
        {
            if(c == 0)
            this.counter++;
            return;
        }
        vis[si][sj] = true;
        c--;
        for(int i = 0; i<=3; i++)
        {
            int nx = si + x[i];
            int ny = sj + y[i];
            if(valid(m, n, nx, ny) && !vis[nx][ny] && grid[nx][ny] != -1)
                count(grid, m, n, nx, ny, vis, c);
        }
        vis[si][sj] = false;
        c++;
    }
    public int uniquePathsIII(int[][] grid) {
        this.counter = 0;
        int m = grid.length;
        int n = grid[0].length;
        int si = -1;
        int sj = -1;
        int c = m * n - 1;
        
        for(int i = 0; i<=m-1; i++)
        {
            for(int j = 0; j<=n-1; j++)
            {
                if(grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
                else if(grid[i][j] == -1)
                    c--;
            }
        }
        boolean[][] vis = new boolean[m][n];
        count(grid, m, n, si, sj, vis, c);
        return this.counter;
            
    }
}
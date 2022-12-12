class Solution {
    
    
    
    public void placeQueen(int n, int i, char[][] grid, List<List<String> > ans)
    {
        
        if(i == n)
        {
            // this is a successful attempt
            List<String> gr = new ArrayList<>();
            for(int j = 0; j<=n-1; j++)
            {
                String str = "";
                for(int k = 0; k<=n-1; k++)
                {
                    if(grid[j][k] == 'X')
                        str += '.';
                    else
                        str += grid[j][k];
                }
                gr.add(str);
            }
            ans.add(gr);
            return;
        }
        
        
        
        
        
        for(int j = 0; j<=n-1; j++)
        {
            if(grid[i][j] != 'X')
            {
                char[][] gridCopy = new char[n][n];

                for(int x = 0; x<=n-1; x++)
                {
                    for(int y = 0; y<=n-1; y++)
                        gridCopy[x][y] = grid[x][y];
                }
                gridCopy[i][j] = 'Q';
                for(int k = i + 1; k<=n-1; k++)
                {
                    gridCopy[k][j] = 'X';
                }
                int ptr = j + 1;
                for(int k = i + 1; k<=n-1 && ptr<=n-1; k++)
                {
                    gridCopy[k][ptr] = 'X';
                    ptr++;
                }
                ptr = j - 1;
                for(int k = i + 1; k<=n-1 && ptr>=0; k++)
                {
                    gridCopy[k][ptr] = 'X';
                    ptr--;
                }
                placeQueen(n, i + 1, gridCopy, ans);
            }
        }
        return;
    }
    
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String> > ans = new ArrayList<>();
        char[][] grid = new char[n][n];
        for(int i = 0; i<=n-1; i++)
        {
            for(int j = 0; j<=n-1; j++)
                grid[i][j] = '.';
        }
        
        placeQueen(n, 0, grid, ans);
        return ans;
    }
}
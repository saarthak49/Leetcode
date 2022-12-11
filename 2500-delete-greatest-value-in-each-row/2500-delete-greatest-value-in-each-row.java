class Solution {
    public int deleteGreatestValue(int[][] grid) {
        int n = grid.length;

        for (int[] ints : grid) {
            Arrays.sort(ints);
        }
        
        
        int sum = 0;
        
        int col = grid[0].length;
        
        for(int j = 0; j<=col-1; j++)
        {
            
            // find the minimum in below
            int max = Integer.MIN_VALUE;
            for(int i = 0; i<=n-1; i++)
            {
                max = Math.max(grid[i][j], max);
            }
            sum += max;
        }
        
        return sum;
    }
}
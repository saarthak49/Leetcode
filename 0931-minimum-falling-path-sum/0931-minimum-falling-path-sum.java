class Solution {
    
    
    private int[] x = {1, 0, -1};
    private int[] y = {1, 1, -1}    ;
    boolean isValid(int i, int n)
    {
        if(i < 0 || i >= n)
            return false;
        return true;
    }
    
    
    
    public int minFallingPathSum(int[][] matrix) {
        
        int n = matrix.length;
        
        int answer = Integer.MAX_VALUE;
        
        int[] dp = new int[n];
        for(int i = 0; i<=n-1; i++)
            dp[i] = 0;
        
        for(int j = n-1; j>=0; j--)
        {
            int[] tempDp = new int[n];
            for(int i = 0; i<=n-1; i++)
            {

                tempDp[i] = matrix[j][i] + dp[i];

                if(isValid(i - 1, n))
                    tempDp[i] = Math.min(tempDp[i], matrix[j][i - 1] + dp[i - 1]);

                if(isValid(i + 1, n))
                    tempDp[i] = Math.min(tempDp[i], matrix[j][i + 1] + dp[i + 1]);
                
                if(j == 0)
                    answer = Math.min(answer, tempDp[i]);   
                
            }
            
            dp = tempDp;
        }
        
        return answer;
            
        
    }
}
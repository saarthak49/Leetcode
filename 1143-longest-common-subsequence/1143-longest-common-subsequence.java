class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        
        
        int n1 = text1.length();
        int n2 = text2.length();
        
        int[] dp = new int[n1 + 1];
        
        for(int i = 1; i<=n2; i++)
        {
            int[] tempDp = new int[n1 + 1];
            
            for(int j = 1; j<=n1; j++)
            {
                if(text2.charAt(i - 1) == text1.charAt(j - 1))
                    tempDp[j] = 1 + dp[j - 1];
                else
                    tempDp[j] = Math.max(tempDp[j - 1], dp[j]);
            }
            dp = tempDp;
        }
        return dp[n1];
        
        
    }
}
class Solution {
    public int rob(int[] nums) {
        
        int n = nums.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 1; i<=n-1; i++)
        {
            dp[i + 1] = Math.max(dp[i], nums[i] + dp[i - 1]);
        }
        return dp[n];
        
    }
}
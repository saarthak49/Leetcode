class Solution {
    public int maxProfit(int[] prices) {
        
        int n = prices.length;
        if(n <= 1)
            return 0;
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        
        
        dp1[0] = -prices[0];
        dp2[0] = 0;
        
        
        dp1[1] = Math.max(-prices[1], dp1[0]);
        dp2[1] = Math.max(prices[1] - prices[0], 0);
        
        
        
            
        for(int i = 2; i<=n-1; i++)
        {
            dp1[i] = Math.max(dp1[i-1], dp2[i-2] - prices[i]);
            dp2[i] = Math.max(dp2[i-1], dp1[i-1] + prices[i]);
        }
        return dp2[n-1] < 0 ? 0 : dp2[n-1];
        
    }
}
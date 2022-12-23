class Solution {
    public int maxProfit(int[] prices) {
        
        int n = prices.length;
        if(n <= 1)
            return 0;
        int a = -prices[0];
        int b = 0;
        int c = Math.max(0, prices[1] - prices[0]);
        
        
        
            
        for(int i = 1; i<=n-1; i++)
        {
            int t = b;
            b = Math.max(b, a + prices[i]);
            a = Math.max(a, c - prices[i]);
            c = t;
        }
        return b;
        
    }
}
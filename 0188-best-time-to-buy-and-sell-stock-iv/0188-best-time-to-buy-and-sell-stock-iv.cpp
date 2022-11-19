class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0 || n == 1 || n == 0)
            return 0;
        if(n == 2)
            return max(0, prices[1] - prices[0]);
        vector<pair<int, int> > dp;
        for(int i = 0; i<=k-1; i++)
        {
            dp.push_back({INT_MIN, INT_MIN});
        }
        
        for(int i = 0; i<=n-1; i++)
        {
            for(int j = 0; j<=k-1; j++)
            {
                if(j == 0)
                {
                    dp[0].first = max(dp[0].first, -prices[i]);
                    dp[0].second = max(dp[0].second, prices[i] + dp[0].first);
                }
                else
                {
                    dp[j].first = max(dp[j].first, dp[j-1].second - prices[i]);
                    dp[j].second = max(dp[j].second, prices[i] + dp[j].first );
                }
                // cout<<dp[j].first<<" "<<dp[j].second<<endl;
            }
        }
        return dp[k - 1].second;
    }
};
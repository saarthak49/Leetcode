class Solution {
public:
    
    
    double getAnswer(vector<int> &nums, int n, int k, double dp[1001][1001], vector<double> cumSum, bool isPresent[1001][1001])
    {
        
        if(n == k)
            return cumSum[n-1];
        
        if(k == 1)
            return cumSum[n-1]/(double) n;
        
        if(isPresent[n][k])
            return dp[n][k];
        
        
        for(int i = 1; i<=n-k+1; i++)
        {
            
            dp[n][k] = max(getAnswer(nums, n-i, k-1, dp, cumSum, isPresent) + (cumSum[n-1] - cumSum[n-i-1])/(double)i, dp[n][k]);
        }
        isPresent[n][k] = true;
        return dp[n][k];
    }
    
    
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        double dp[1001][1001];
        bool isPresent[1001][1001];
        memset(dp, 0, sizeof(dp));
        memset(isPresent, false, sizeof(isPresent));
        vector<double> cumSum;
        cumSum.push_back(nums[0]);
        for(int i = 1; i<=n-1; i++)
        {
            cumSum.push_back(cumSum[i-1] + nums[i]);
        }
        return getAnswer(nums, n, k, dp, cumSum, isPresent);
        
    }
};
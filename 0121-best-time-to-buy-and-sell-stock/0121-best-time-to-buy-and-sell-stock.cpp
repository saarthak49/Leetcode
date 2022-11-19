class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)
            return 0;
        int minSeenSoFar = prices[0];
        int answer = 0;
        for(int i = 1; i<=n-1; i++)
        {
            answer = max(answer, prices[i] - minSeenSoFar);
            minSeenSoFar = min(minSeenSoFar, prices[i]);
        }
        return answer;
        
    }
};
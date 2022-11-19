class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fb = INT_MIN;
        int fs = INT_MIN;
        int sb = INT_MIN;
        int ss = INT_MIN;
        int n = prices.size();
        for(int i = 0; i<=n-1; i++)
        {
            fb = max(fb , -prices[i]);
            fs = max(fs, fb + prices[i]);
            sb = max(sb, fs - prices[i]);
            ss = max(ss, sb + prices[i]);
            // cout<<fb<<" "<<fs<<" "<<sb<<" "<<ss<<endl;
        }
        return ss;
        
    }
};
class Solution {
public:
    static const int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp0[high + 1];
        memset(dp0, 0, sizeof(dp0));
        
        int dp1[high + 1];
        memset(dp1, 0, sizeof(dp1));
        
        int dpt[high + 1];
        memset(dpt, 0, sizeof(dpt));
        
        dp0[0] = 1;
        dp1[0] = 1;
        dpt[0] = 1;
        int numberWays = 0;
        for(int i = 1; i<=high; i++)
        {
            if(i - zero >= 0)
                dp0[i] = dpt[i - zero];
            if(i - one >= 0)
                dp1[i] = dpt[i - one];
            
            dpt[i] = (dp0[i] % mod + dp1[i] % mod) % mod;
            
            if(i >= low && i <= high)
                numberWays = (numberWays % mod +  dpt[i] % mod ) % mod;
        }
        
        return numberWays;
        
    }
};
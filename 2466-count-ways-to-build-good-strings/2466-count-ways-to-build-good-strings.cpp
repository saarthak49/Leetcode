class Solution {
public:
    static const int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        int dpt[high + 1];
        memset(dpt, 0, sizeof(dpt));
        dpt[0] = 1;
        int numberWays = 0;
        for(int i = min(one, zero); i<=high; i++)
        {
            if(i >= zero)
                dpt[i] = (dpt[i] % mod +  dpt[i - zero] % mod )  % mod;
            if(i >= one)
                dpt[i] = (dpt[i] % mod  + dpt[i - one] % mod) % mod;
            
            if(i >= low && i <= high)
                numberWays = (numberWays % mod +  dpt[i] % mod ) % mod;
        }
        
        return numberWays;
        
    }
};
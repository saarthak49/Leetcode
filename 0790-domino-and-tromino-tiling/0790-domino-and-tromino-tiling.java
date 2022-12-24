class Solution {
    
    private static final int mod = (int)1e9+7;
    
    
    public int numTilings(int n) {
        
        
        int[] h = new int[n + 1];
        int[] sum = new int[n + 1];
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        
        h[0] = 1;
        h[1] = 1;
        h[2] = 2;
        
        sum[0] = 1;
        sum[1] = 2;
        sum[2] = 4;
        
        int a = 2;
        int b = 1;
        int total = 2;
        
        for(int i = 3; i<=n; i++)
        {
            int flatTiles = (a%mod + b%mod)%mod;
            
            int t = (sum[i - 3] % mod * 2 % mod ) % mod;
            total = (flatTiles % mod + t % mod ) % mod;
            
            sum[i] = (total%mod + sum[i-1]%mod ) % mod;
            b = a;
            a = total;
        }
        return total;
            
        
        
    }
}
class Solution {
    
    private static final int mod = (int)1e9+7;
    
    
    public int numTilings(int n) {
        
        
        int[] f = new int[n + 1];
        int[] g = new int[n + 1];
        int[] h = new int[n + 1];
        int[] sum = new int[n + 1];
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        
        
        
        
        f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        
        g[0] = 1;
        g[1] = 1;
        g[2] = 1;
        
        h[0] = 1;
        h[1] = 1;
        h[2] = 2;
        
        sum[0] = 1;
        sum[1] = 2;
        sum[2] = 4;
        
        int a = 2;
        int b = 1;
        
        
        for(int i = 3; i<=n; i++)
        {
            f[i] = (a%mod + b%mod)%mod;
            
            int t = (sum[i - 3] % mod * 2 % mod ) % mod;
            h[i] = (f[i]%mod + t%mod ) % mod;
            
            sum[i] = (h[i]%mod + sum[i-1]%mod ) % mod;
            b = a;
            a = h[i];
        }
        return h[n];
            
        
        
    }
}
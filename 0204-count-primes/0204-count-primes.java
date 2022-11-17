class Solution {
    
    
    public int getPrimes(int n )
    {
        boolean[] list = new boolean[n];
        
        for(int i = 0; i<=n-1; i++)
        {
            list[i] = true;
        }
        
        for(int i = 2; i<=Math.sqrt(n); i++)
        {
            if(list[i])
            {
                for(int j = i*i; j<=n-1; j+=i)
                {
                    list[j] =  false;
                }
            }
        }
        
        int countPrimes = 0;
        for(int i=2; i<=n-1; i++)
        {
            if(list[i])
                countPrimes++;
        }
        
        return countPrimes;
    }
    
    
    public int countPrimes(int n) {
        return getPrimes(n);
    }
}
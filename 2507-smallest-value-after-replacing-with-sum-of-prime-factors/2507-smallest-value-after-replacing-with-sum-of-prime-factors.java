class Solution {
    
    
    
    
    
    
    public boolean isPrime(int n)
    {
        int count = 0;
        
        for(int i = 1; i<=Math.sqrt(n); i++)
        {
            if(n % i == 0)
            {
                int a = i;
                int b = n/i;
                
                if(a == b)
                    count++;
                else 
                    count += 2;
            }
        }
        
        
        return count == 2;
    }
    
    
    
    
    
    public int smallestValue(int n) {
        
        
        
        int sum = 0;
        
        
        while(!isPrime(n))
        {
            int t = n;
            for(int i = 2; i<=t/2; i++)    
            {
                while(n % i == 0 && isPrime(i))
                {
                    sum += i;
                    n/=i;
                }
            }
            n = sum;
            sum = 0;
            if(t == n)
                break;
        }
        return n;
        
    }
}
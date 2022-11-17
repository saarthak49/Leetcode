class Solution {
public:
    
    // advanced sieve is not working somehow
    vector<int> getSieve(int n)
    {
        vector<int> primes;
        vector<int> numbers(n + 1, 0);
        for(int i = 0; i<=n; i++)
        {
            numbers[i] = i;
        }
        
        
        for(int i = 2; i<=n-1; i++)
        {
            if(numbers[i] == i)
            {
                primes.push_back(i);
            }
            
            int s = primes.size();
                
            for(int k = 0; k<=s-1 && primes[k]<=i && i*primes[k]<=n-1; k++)
            {
                numbers[i * primes[k]] = primes[k];
            }
        }
        
        return primes;
    }
    
    
    int tryingSimpleSieve(int n)
    {
        // assuming all the numbers are prime numbers
        vector<bool> vec(n, true);
        
        int countPrimes = 0;
        for(int i = 2; i<=sqrt(n); i++)
        {
            if(vec[i] == true)
            {
                for(int j = i*i ; j<=n-1; j+=i)
                {
                    vec[j] = false;
                }
            }
        }
        
        for(int i = 2; i<=n-1; i++)
        {
            if(vec[i] == true)
                countPrimes++;
        }
            
        return countPrimes;
    }
    
    int countPrimes(int n) {
        
        if(n == 0 || n == 1)
            return 0;
        
        
        return tryingSimpleSieve(n);
        
    }
};
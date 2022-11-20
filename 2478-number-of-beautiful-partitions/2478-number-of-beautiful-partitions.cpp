class Solution {
public:
    
    static const int mod = 1e9 + 7;
    
    
    bool isPrime(char ch)
    {
        if(ch == '2' || ch=='3' || ch=='5' || ch=='7')
            return true;
        return false;
    }
    
    
    void getAnswer(string s, int k ,int minLength, int dp[1001][1001])
    {
        
        // cout<<"printing the string\n";
        
            
        int n = s.size();
        // for(int i = 0; i<=n-1; i++)
        //     cout<<s[i]<<" ";
        cout<<endl;
        minLength = max(2, minLength);
        
        dp[0][0] = 1;
        for(int i = 1; i<=n-1; i++)
        {
            // whether or not a cut is possible at s[i] 
            // so that i - n-1 is a valid segment
            if(!isPrime(s[i-1]) && isPrime(s[i]) && n-i >= minLength)
                dp[i][0] = 1;
            
        }
            
            
            
            
        for(int c = 1; c<=k; c++)
        {
            vector<int> suffix(n, 0);
            suffix[n-1] = dp[n-1][c-1];
            for(int i = n-2; i>=0; i--)
                suffix[i] = (dp[i][c-1] % mod + suffix[i+1] % mod ) % mod;


//             cout<<"printing the dp array\n";
//             for(int i = 0; i<=n-1; i++)
//             {
//                 cout<<dp[i][c-1]<<" ";
//             }

//             cout<<endl;
//             cout<<"printing the suffix array\n";
//             for(int i = 0; i<=n-1; i++)
//                 cout<<suffix[i]<<" ";
//             cout<<endl;



            for(int i = 0; i<=n-1; i++)
            {
                if(!isPrime(s[i]) || (i>=1 && isPrime(s[i-1])))
                {
                    dp[i][c] = 0;
                    continue;
                }
                int j = i + minLength;
                for(; j<=n-1; j++)
                {
                    if(!isPrime(s[j - 1]) && isPrime(s[j]))
                    {
                        break;
                    }
                }
                if(j<=n-1)
                    dp[i][c] = suffix[j];
                else
                    dp[i][c] = 0;
            }

        }

        // cout<<"printing the dp array\n";
        // for(int i = 0; i<=n-1; i++)
        // {
        //     cout<<dp[i][k]<<" ";
        // }

        cout<<endl;
        // cout<<"printing the suffix array\n";
        // for(int i = 0; i<=n-1; i++)
        //     cout<<suffix[i]<<" ";
        // cout<<endl;
    }
        



    int beautifulPartitions(string s, int k, int minLength) {

        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));

        int n = s.size();
        if(!n)
            return 0;


        if(!isPrime(s[0]) || isPrime(s[n-1]))
            return 0;

        getAnswer(s, k-1, minLength, dp);
        return dp[0][k-1];

    }
};
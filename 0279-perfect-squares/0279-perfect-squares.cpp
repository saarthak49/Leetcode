class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 2; i*i <= n; i++)
        {
            squares.push_back(i*i);
        }
        
        vector<int> dp1(n+1, 0);
        for(int i = 0; i<=n; i++)
            dp1[i] = i;
        
        
        if(n == 1 || n == 2 || n == 3)
            return n;
        
        vector<int> dp2(n+1, 0);
        
        int sizeOfSquares = squares.size();
        for(int i = 0; i<=sizeOfSquares-1; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(j < squares[i])
                    dp2[j] = dp1[j];
                else
                {
                    dp2[j] = min(dp1[j], dp2[j - squares[i]] + 1);
                }
            }
            
            for(int j = 1; j<=n; j++)
            {
                dp1[j] = dp2[j];
                // cout<<dp1[j]<<" ";
            }
            // cout<<endl;
        }
        
        
        
        return dp2[n];
        
        
        
        
    }
};

class Solution {
public:
    
    
    
    
    // Manacher Algorithm
    
    string longestPalindrome(string s) {
        int n = s.size();
        n = 2*n + 1;
        vector<int> lps(n, 0);
        lps[0] = 0;
        lps[1] = 1;
        int C = 1;
        int R = 2;
        int i = 2;
        bool expand = false;
        while(i<=n-1)
        {
            bool expand = false;
            int leftImage = 2*C - i;
            int diff = R - i;
            if(diff>=0)
            {
                if(i + lps[leftImage] == R)
                {
                    if(R <= n - 1)
                        expand = true;
                }
                else if( i + lps[leftImage] < R)
                {
                 
                    lps[i] = lps[leftImage];
                }
                else if( i + lps[leftImage] > R)
                {
                    lps[i] = diff;
                }
            }
            else
            {
                expand = true;
            }
            
            if(expand)
            {
                int count = 0;
                int j = i - 1;
                int k = i + 1;
                while(j>=0 && k<=n-1 && j%2==0 || j>=0 && k<=n-1 && (s[(j-1)/2] == s[(k-1)/2]) )
                {
                    count++;
                    j--;
                    k++;
                }
                lps[i] = count;
                if(lps[i] + i > R)
                {
                    R = i + lps[i];
                    C = i;
                }
            }
            i++;
            // for(int p = 0; p<=n-1; p++)
            // cout<<lps[p]<<" ";
            // cout<<endl;
        }
        
        
        int maxLength = 0;
        int start = 0;
        int stop = 0;
        for(int i = 0; i<=n-1; i++)
        {
            if(lps[i] > maxLength)
            {
                //update start and end
                maxLength = lps[i];
                if(maxLength %2 == 0)
                {
                    stop = i + maxLength - 1;
                    start = i - maxLength + 1;
                }
                else
                {
                    stop = i + maxLength - 1;
                    start = i - maxLength + 1;
                }
            }
        }
        
        start = (start - 1)/2;
        stop = (stop - 1)/2;
        string answer = "";
        for(i = start; i<=stop; i++)
            answer += s[i];
        return answer;
    }
};
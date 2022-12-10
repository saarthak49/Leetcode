int dp[101][101][27][101];
class Solution {
public:
    
     
    int solve( int index, string &s, int k, char prevChar, int freqOfPrevChar)
    {
        int n = s.length();
        if(k<0)return n;
        if(index>=n)return 0;
        
        if(dp[index][k][prevChar-'a'][freqOfPrevChar]!=-1){
            return dp[index][k][prevChar-'a'][freqOfPrevChar];
        }
        
        int res = solve(index+1, s, k-1, prevChar, freqOfPrevChar);
        
        if(prevChar!=s[index]){
            res = min(res, 1+solve(index+1, s, k, s[index], 1));
        }
        else{
            int x = 0;
            if(freqOfPrevChar==9 || freqOfPrevChar==1 || freqOfPrevChar==99){
                x++;
            }
            x+=solve(index+1, s, k, s[index], 1+freqOfPrevChar);
            res = min(res, x);
        }
        
        dp[index][k][prevChar-'a'][freqOfPrevChar] = res;
            
        return res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();        
        int ans;        
        memset(dp, -1, sizeof(dp));    
        
        //here sending char('z' + 1) is very important  !!
        ans = solve(0, s, k, char('z' + 1), 0);
        return ans;
    }
};
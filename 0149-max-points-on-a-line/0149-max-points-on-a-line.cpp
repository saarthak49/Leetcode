class Solution {
public:
    
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int maxPointsOnLine = 0;
        for(int i = 0; i<=n-1; i++)
        {
            
            unordered_map<string, int> mp;
            int xcurr = points[i][0];
            int ycurr = points[i][1];
            // int maxHere = 0;
            
            for(int j = 0; j<=n-1; j++)
            {
                if(j==i)
                    continue;
                int xnew = points[j][0];
                int ynew = points[j][1];
                int xdiff = 0;
                int ydiff = 0;
                string key = "";
                if(ynew == ycurr )
                {
                    xdiff = 1;
                    ydiff = 0;
                }
                else if( xnew == xcurr)
                {
                    xdiff = 0;
                    ydiff = 1;
                }
                else
                {
                    xdiff = xcurr - xnew;
                    ydiff = ycurr - ynew;
                    int gcd = __gcd(abs(xdiff), abs(ydiff));
                    xdiff /= gcd;
                    ydiff /= gcd;
                }
                key = to_string(xdiff) + ',' + to_string(ydiff);
                mp[key]++;
                maxPointsOnLine = max(maxPointsOnLine, mp[key] );
            }
            // maxPointsOnLine = max(maxPointsOnLine, maxHere + 1);
            
            
        }
        return maxPointsOnLine + 1;
        
    }
};
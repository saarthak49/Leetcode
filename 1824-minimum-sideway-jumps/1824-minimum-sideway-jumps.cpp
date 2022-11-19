class Solution {
public:
    bool isBlocked(vector<int> &obstacles, int lane, int i)
    {
        return obstacles[i] == lane;
    }
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<int> dp1(n, 1e6);
        vector<int> dp2(n, 1e6);
        vector<int> dp3(n, 1e6);
        
        
        dp1[0] = isBlocked(obstacles, 1, 0) ? 1e6 : 1;
        dp2[0] = isBlocked(obstacles, 2, 0) ? 1e6 : 0;
        dp3[0] = isBlocked(obstacles, 3, 0) ? 1e6 : 1;
        
        for(int i = 1; i<=n - 1; i++)
        {
            
//             if(!isBlocked(obstacles, 1, i))
//             {
//                 if(!isBlocked(obstacles, 1, i - 1))
//                     dp1[i] = min(dp1[i], dp1[i - 1]);
//                 if(!isBlocked(obstacles, 2, i - 1)  && (!isBlocked(obstacles, 1, i - 1) || !isBlocked(obstacles, 2, i)))
//                     dp1[i] = min(dp1[i], 1 + dp2[i - 1]);
//                 if(!isBlocked(obstacles, 1, i) && !isBlocked(obstacles, 3, i-1) && (!isBlocked(obstacles, 1, i-1)||!isBlocked(obstacles, 3, i)))
//                    dp1[i] = min(dp1[i], 1 + dp3[i-1]);
//             }
            
                   
//             if(!isBlocked(obstacles, 3, i))
//             {
//                 if(!isBlocked(obstacles, 3, i - 1))
//                     dp3[i] = min(dp3[i], dp3[i - 1]);
//                 if(!isBlocked(obstacles, 2, i - 1)  && (!isBlocked(obstacles, 3, i - 1) || !isBlocked(obstacles, 2, i)))
//                     dp3[i] = min(dp3[i], 1 + dp2[i - 1]);
//                 if(!isBlocked(obstacles, 3, i) && !isBlocked(obstacles, 1, i-1) && (!isBlocked(obstacles, 3, i-1)||!isBlocked(obstacles, 1, i)))
//                    dp3[i] = min(dp3[i], 1 + dp1[i-1]);
//             }
                   
//             if(!isBlocked(obstacles, 2, i))
//             {
//                 if(!isBlocked(obstacles, 2, i - 1))
//                     dp2[i] = min(dp2[i], dp2[i - 1]);
//                 if(!isBlocked(obstacles, 1, i - 1)  && (!isBlocked(obstacles, 2, i - 1) || !isBlocked(obstacles, 1, i)))
//                     dp2[i] = min(dp2[i], 1 + dp1[i - 1]);
//                 if(!isBlocked(obstacles, 3, i - 1)  && (!isBlocked(obstacles, 2, i - 1) || !isBlocked(obstacles, 3, i)))
//                    dp2[i] = min(dp2[i], 1 + dp3[i-1]);
//             }
            
            dp1[i] = isBlocked(obstacles, 1, i) ? INT_MAX : dp1[i-1];
            dp2[i] = isBlocked(obstacles, 2, i) ? INT_MAX : dp2[i-1];
            dp3[i] = isBlocked(obstacles, 3, i) ? INT_MAX : dp3[i-1];
            if(!isBlocked(obstacles, 1, i))
            {
                if(!isBlocked(obstacles, 2, i) && dp2[i] != INT_MAX)
                    dp1[i] = min(dp1[i], dp2[i] + 1);
                
                if(!isBlocked(obstacles, 3, i) && dp3[i] != INT_MAX)
                    dp1[i] = min(dp1[i], dp3[i] + 1);
            }
            
            if(!isBlocked(obstacles, 2, i))
            {
                if(!isBlocked(obstacles, 1, i) && dp1[i] != INT_MAX)
                    dp2[i] = min(dp2[i], dp1[i] + 1);
                
                if(!isBlocked(obstacles, 3, i) && dp3[i] != INT_MAX)
                    dp2[i] = min(dp2[i], dp3[i] + 1);
            }
            
            if(!isBlocked(obstacles, 3, i))
            {
                if(!isBlocked(obstacles, 2, i) && dp2[i] != INT_MAX)
                    dp3[i] = min(dp3[i], dp2[i] + 1);
                
                if(!isBlocked(obstacles, 1, i) && dp1[i] != INT_MAX)
                    dp3[i] = min(dp3[i], dp1[i] + 1);
            }
                   
        }
                   
        return min(dp2[n-1], min(dp1[n-1], dp3[n-1]));
        
    }
};
    

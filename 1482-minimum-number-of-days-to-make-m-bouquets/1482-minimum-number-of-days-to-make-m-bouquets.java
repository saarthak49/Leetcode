class Solution {
    
    private boolean check(int[] bloomDay, int days, int m, int k)
    {
        int streak = 0;
        int streakCounter = 0;
        for(int num: bloomDay)
        {
            if(num <= days)
                streak++;
            else    
                streak = 0;
        
            if(streak == k)
            {
                streakCounter++;
                streak = 0;
            }
            
            if(streakCounter == m)
                return true;
            
        }
        return false;
    }
    
    public int minDays(int[] bloomDay, int m, int k) {
        
        int n = bloomDay.length;
        
        if(n < m * k)
            return -1;
        
        int minimum = Integer.MAX_VALUE;
        int maximum = Integer.MIN_VALUE;
        
        for(int i = 0; i<=n-1; i++)
        {
            minimum = Math.min(minimum, bloomDay[i]);
            maximum = Math.max(maximum, bloomDay[i]);
        }
        int ans = -1;
        while(minimum <= maximum)
        {
            int mid = minimum + (maximum - minimum) / 2;
            if(check(bloomDay, mid, m, k))
            {
                ans = mid;
                // try for smaller value also
                maximum = mid - 1;
            }
            else
            {
                //increase the value of minimum number of days required
                minimum = mid + 1;
            }
        }
        
        return ans;
        
    }
}
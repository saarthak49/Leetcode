class Solution {
    
    
    private int[] dp;
    
    Solution()
    {
        this.dp = new int[(int)1e5 + 1];
        dp[1] = 1;
        for(int i = 2; i<=(int)1e5; i++)
            dp[i] = Math.min(dp[i-2], (i-3)>=0?dp[i-3]:0) + 1;
    }
    
    
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        for(int task : tasks)
            mp.put(task, mp.getOrDefault(task,0)+1);
        
        int count = 0;
        for(int value : mp.values())
        {
            if(value == 1)
                return -1;
            else
                count += dp[value];
        }
        return count;
    }
}
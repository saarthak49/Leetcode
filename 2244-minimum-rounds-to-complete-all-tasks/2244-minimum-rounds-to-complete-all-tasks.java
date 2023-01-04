class Solution {
    
    
    private final int[] dp;
    
    Solution()
    {
        this.dp = new int[(int)1e5+1];
        dp[2] = 1;
        dp[3] = 1;
        dp[1] = 1;
        for(int i = 4; i<=100000; i++)
            dp[i] = Math.min(dp[i-2], dp[i-3]) + 1;
    }
    
    
    
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        
        for(int task : tasks)
        {
            if(mp.containsKey(task))
                mp.put(task, mp.get(task) + 1);
            else
                mp.put(task, 1);
        }
        
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
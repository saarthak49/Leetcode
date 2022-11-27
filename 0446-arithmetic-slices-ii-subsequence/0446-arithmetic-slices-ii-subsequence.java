class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        
        Map<Long, Long> mp = new HashMap<>();
        mp.put(0L, 0L);
        
        List<Map<Long, Long> > dp = new ArrayList<>();
        
        for(int i = 0; i<=n-1; i++)
            dp.add(mp);
        
        
        dp.set(0, mp);
        
        for(int i = 1; i<=n-1; i++)
        {
            Map<Long, Long> tempMap = new HashMap<>();
            for(int j = 0; j<=i-1; j++)
            {
                long cd = (long)nums[i] - nums[j];
                long prev = 0;
                long curr = 0;
                if(dp.get(j).containsKey(cd))
                    prev = dp.get(j).get(cd);
                
                
                if(tempMap.containsKey(cd))
                    curr = tempMap.get(cd);
                
                tempMap.put(cd, prev + curr + 1);
            }
            dp.set(i, tempMap);
        }
        
        long sum = 0;
        for(Map<Long, Long> te: dp)
        {
            for(long val: te.values())
                sum += val;
        }
        
        
        return (int)(sum - (long)n * (n-1)/2);
        
        
    }
}
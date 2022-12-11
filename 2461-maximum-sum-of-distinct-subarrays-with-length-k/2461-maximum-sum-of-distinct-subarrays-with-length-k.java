class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        
        
        
        
        
        int n = nums.length;
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        long maxSum = 0;
        
        long sum = 0L;
        
        for(int i = 0; i<=k-1; i++)
        {
            
            if(mp.containsKey(nums[i]))
                mp.put(nums[i], mp.get(nums[i]) + 1);
            else
                mp.put(nums[i], 1);
            sum += nums[i];
        }
        
        if(mp.size() == k)
            maxSum = Math.max(maxSum, sum);
        
        for(int i = k; i<=n-1; i++)
        {
            mp.put(nums[i - k], mp.get(nums[i - k]) - 1);
            if(mp.get(nums[i - k]) == 0)
                mp.remove(nums[i - k]);
            
        
        
            sum -= nums[i - k];
            sum += (long)nums[i];
            if(mp.containsKey(nums[i]))
                mp.put(nums[i], mp.get(nums[i]) + 1);
            else
                mp.put(nums[i], 1);
            if(mp.size() == k)
                maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
        
        
        
        
    }
}
class Solution {
    public int countKDifference(int[] nums, int k) {
        
        
        Map<Integer, Integer> mp = new HashMap<>();
        
        int n = nums.length;
        int count = 0;
        for(int i = 0; i<=n-1; i++)
        {
            
            
            if(mp.containsKey(nums[i] - k))
                count += mp.get(nums[i] - k);
            
            if(mp.containsKey(nums[i] + k))
                count += mp.get(nums[i] + k);
            if(mp.containsKey(nums[i]))
                mp.put(nums[i], mp.get(nums[i]) + 1);
            else
                mp.put(nums[i], 1);
        }
        
        return count;
        
    }
}
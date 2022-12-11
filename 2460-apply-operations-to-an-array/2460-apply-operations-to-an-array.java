class Solution {
    
    public void modify(int[] nums)
    {
        int idx = 0;
        
        int n = nums.length;
        for(int i = 0; i<=n-1; i++)
        {
            if(nums[i] > 0)
            {
                int t = nums[i];
                nums[i] = nums[idx];
                nums[idx] = t;
                idx++;
            }
        }
    }
    
    public int[] applyOperations(int[] nums) {
        
        int n = nums.length;
        
        for(int i = 0; i<=n-2; i++)
        {
            if(nums[i] == nums[i + 1])
            {
                nums[i] *=2;
                nums[i+1] = 0;
            }
            
        }
        
        modify(nums);
        return nums;
        
    }
}
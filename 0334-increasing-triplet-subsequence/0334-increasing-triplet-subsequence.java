class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        if(n <= 2)
            return false;
        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;
        
        for(int i = 0; i<=n-1; i++)
        {
            if(nums[i] < smallest)
                smallest = nums[i];
            else if(nums[i] > smallest && nums[i] < secondSmallest)
                secondSmallest = nums[i];
            else if(nums[i] > secondSmallest)
                return true;
            
        }
        return false;
    }
}
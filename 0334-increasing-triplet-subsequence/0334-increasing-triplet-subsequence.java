class Solution {
    public boolean increasingTriplet(int[] nums) {
        
        int n = nums.length;
        
        if(n<=2)
            return false;
        
        boolean[] arr = new boolean[n];
        
        
        // 
        
        int track = nums[0];
        for(int i = 1; i<=n-2; i++)
        {
            
            if(track < nums[i])
                arr[i] = true;
            else
                track = nums[i];
        }
        
        track = nums[n-1];
        for(int i = n-2; i>=1; i--)
        {
            if(track > nums[i] && arr[i])
                return true;
            else if(track <= nums[i])
                track = nums[i];
        }
        return false;
    }
}
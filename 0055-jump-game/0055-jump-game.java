class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int maxReach = 0;
        int i = 0;
        
        while(i <= n-1 && i <= maxReach)
        {
            maxReach = Math.max(maxReach, i + nums[i]);
            i++;
        }
        if(i == n)
            return true;
        return false;
    }
}
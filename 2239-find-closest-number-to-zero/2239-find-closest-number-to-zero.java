class Solution {
    public int findClosestNumber(int[] nums) {
        int dist = Integer.MAX_VALUE;
        int closest = -1;
        
        for(int i = 0; i<=nums.length - 1; i++)
        {
            int newDist = Math.abs(nums[i] - 0);
            if(newDist < dist)
            {
                closest = nums[i];
                dist = newDist;
            }
            else if(newDist == dist)
                closest = Math.max(closest, nums[i]);
        }
        return closest;
        
    }
}
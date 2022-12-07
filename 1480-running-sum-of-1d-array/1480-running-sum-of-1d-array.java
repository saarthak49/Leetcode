class Solution {
    public int[] runningSum(int[] nums) {
        int sum = 0;
        int n = nums.length;
        int[] runningSum = new int[n];
        for(int i = 0; i<=n-1; i++)
            runningSum[i] = i > 0 ? runningSum[i - 1] + nums[i] : nums[0];
        
        return runningSum;
        
    }
}
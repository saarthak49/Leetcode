class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int sum = 0;

        int currMax = 0;
        int currMin = 0;
        int maxSum = nums[0];
        int minSum = nums[0];

        for(int i = 0; i < nums.length; i++){
            currMax += nums[i];
            maxSum = Math.max(currMax, maxSum);
            if(currMax < 0){
                currMax = 0;
            }

            currMin += nums[i];
            minSum = Math.min(currMin, minSum);
            if(currMin > 0){
                currMin = 0;
            }

            sum += nums[i];
        }

        return sum == minSum ? maxSum : Math.max(maxSum, sum - minSum);
    }
}
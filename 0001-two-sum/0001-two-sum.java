class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        
        int[] ans = new int[2];
        
        for(int i = 0; i<=n-1; i++)
        {
            int look = target - nums[i];
            if(mp.containsKey(look))
            {
                int index = mp.get(look);
                ans[0] = index;
                ans[1] = i;
                break;
            }
            mp.put(nums[i], i);
        }
        return ans;
    }
}
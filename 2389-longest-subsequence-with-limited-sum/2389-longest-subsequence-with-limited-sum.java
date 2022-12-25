class Solution {
    
    
    int find(int[] nums, int key)
    {
        int low = 0;
        int high = nums.length - 1;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] <= key)
            {
                ans = mid;
                low = mid + 1;
            }
            else 
            {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
    
    
    public int[] answerQueries(int[] nums, int[] queries) {
        
        int n = nums.length;
        Arrays.sort(nums);
        
        
        for(int i = 1; i<=n-1; i++)
            nums[i] += nums[i - 1];
        
        
        int q = queries.length;
        int[] ans = new int[q];
        for(int i = 0; i<=q-1; i++)
        {
            ans[i] = find(nums, queries[i]);
        }
        return ans;
    }
}
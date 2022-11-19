class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int rIndex = -1;
        int lIndex = -1;
        int smallest = INT_MAX;
        int largest = INT_MIN;
        int n = nums.size();
        for(int i = n-1; i>=0; i--)
        {
            smallest = min(smallest, nums[i]);
            if(nums[i] != smallest)
            {
                
                lIndex = i;
            }
        }
        for(int i = 0; i<=n-1; i++)
        {
            largest = max(largest, nums[i]);
            if(nums[i] != largest)
                rIndex = i;
        }
        if(rIndex == -1)
            return 0;
        return rIndex - lIndex + 1;
    }
};
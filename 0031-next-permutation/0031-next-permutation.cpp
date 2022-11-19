class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        // you can use the next_permutation method also like given so 
        // it does in place changes.
        // next_permutation(nums.begin(), nums.end());
        
        int n = nums.size();
        int j = n - 1;
        while(j>=1 && nums[j - 1] >= nums[j])
            j--;
        
        if(j == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int element = nums[j - 1];
            
        int i = n-1;
        for(; i>=j; i--)
        {
            if(nums[i] > element)
                break;
        }
        swap(nums[j-1], nums[i]);
        sort(nums.begin() + j, nums.end());
            
        
    }
};
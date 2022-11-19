class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int numberOfPositives = 0;
        for(int i = 0; i<= n-1; i++)
        {
            if(nums[i] >= 1 )
                numberOfPositives++;
        }
        
        if(numberOfPositives == 0)
            return 1;
        
        int index = 0;
        for(int i = 0; i<=n-1; i++)
        {
            if(nums[i] >= 1 )
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        
        // for(auto it: nums)
        //     cout<<it<<" ";
        // cout<<endl;
        
        for(int i = 0; i<=n-1 && i<= numberOfPositives - 1; i++)
        {
            if(abs(nums[i]) >= 1 && abs(nums[i]) <= (numberOfPositives  ))
            {
                if(nums[abs(nums[i]) - 1] > 0)
                    nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        int answer = -1;
        for(int i = 0;  i<=n-1 && i<= numberOfPositives - 1; i++)
        {
            if(nums[i] >= 0)
                return i+1;
        }
        return numberOfPositives + 1;
        
    }
};
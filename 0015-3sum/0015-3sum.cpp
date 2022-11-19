class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > ans;
        for(int i = 0; i<= n - 3; i++)
        {
            if( i - 1 >= 0 && nums[i - 1] == nums[i])
                continue;
            int j = i + 1; 
            int k = n - 1;
            int target = 0 - nums[i];
            while(j < k)
            {
                if(nums[j] + nums[k] < target)
                    j++;
                else if(nums[j] + nums[k] > target)
                    k--;
                else
                {
                    // this is a pair
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    while( j + 1 <= n - 1 && nums[j + 1] == nums[j])
                        j++;
                    while( k - 1 >= 0 && nums[k - 1] == nums[k])
                        k--;
                    j++;
                    k--;
                }
            }
            
        }
        return ans;
    }
};
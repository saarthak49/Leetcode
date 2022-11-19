class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> store;
        
        int n = nums.size();
        for(int i = 0; i<=n-1; i++)
        {
            if(store.size() == 0)
            {
                store.push_back(nums[i]);
            }
            else
            {
                if(lower_bound(store.begin(), store.end(), nums[i]) != upper_bound(store.begin(), store.end(), nums[i]))
                {
                    continue;
                }
                else
                {
                    int index = upper_bound(store.begin(), store.end(), nums[i]) - store.begin();
                    int storeSize = store.size();
                    if(index >= storeSize)
                        store.push_back(nums[i]);
                    else
                    {
                        if(nums[i] < store[index])
                            store[index] = nums[i];
                    }
                }
            }
        }
        return store.size();
        
    }
};
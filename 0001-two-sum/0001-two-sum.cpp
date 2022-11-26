class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i = 0; i<=n-1; i++)
        {
            int look = target - nums[i];
            if(mp.find(look) != mp.end())
            {
                int index = mp[look];
                ans.push_back(index);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
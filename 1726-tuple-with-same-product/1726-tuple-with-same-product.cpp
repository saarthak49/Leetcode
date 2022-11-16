class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        int n = nums.size();
        
        for(int i = 0; i<=n-1; i++)
        {
            for(int j = i + 1; j<=n-1; j++)
            {
                mp[nums[i] * nums[j]]++;
            }
        }
        
        int count = 0;
        for(auto it: mp)
        {
            int val = it.second * (it.second - 1)/2;
            count += val * 8;
            
        }
        return count;
        
    }
};
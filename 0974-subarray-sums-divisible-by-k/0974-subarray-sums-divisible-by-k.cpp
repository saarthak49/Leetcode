class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int count = 0;
        
        unordered_map<int, int> mp;
        int n = nums.size();
        mp[0] = 1;
        int sum = 0;
        for(int i = 0; i<=n-1; i++)
        {
            sum = (sum % k + nums[i] % k ) % k;
            if(sum < 0)
                sum = (sum + k) %k;
            mp[sum]++;
        }
        for(auto it: mp)
        {
            if(it.second > 0)
                count += it.second * (it.second - 1) / 2;
        }
        return count;
        
    }
};
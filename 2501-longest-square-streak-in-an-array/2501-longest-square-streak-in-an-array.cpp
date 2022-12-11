class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long int, int> mp;
    int n = nums.size();
    for(int i = 0; i<=n-1; i++)
    {
        mp[(long long int)nums[i]] = 1;
    }


    int maxl = 0;
    for(int i = 0; i<=n-1; i++)
    {
        int count = 1;
        // if(mp.find(sqrt(nums[i])) == mp.end())
        // {
            
            
            long long int x = (long long int)nums[i] * nums[i];
            while(mp.find(x) != mp.end())
            {
                count++;
                x *= x;
            }
        // }
        maxl = max(count, maxl);
    }
    return maxl >= 2 ? maxl : -1;
    }
};
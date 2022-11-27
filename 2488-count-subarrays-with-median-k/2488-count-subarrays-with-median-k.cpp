class Solution {
public:
    int findSmallerThanK(vector<int> nums, int k)
    {
        int count = 0;
        for(auto it: nums)
        {
            if(it < k)
                count++;
        }
        return count;
    }
    int findGreaterThanK(vector<int> nums, int k)
    {
        int count = 0;
        for(auto it: nums)
        {
            
            if(it > k)
                count++;
        }
        return count;
    }
    int c(int l, int p)
    {
        if(p > l)
            return 0;
        if(l == 0 || p == 0)
            return 1;
        int answer = 1;
        for(int i = p + 1; i<=l; i++)
        {
            answer *= i;
            answer /= (i - p);
        }
        return answer;
    }
    int findK(vector<int> nums, int k)
    {
        for(int i = 0; i<=nums.size() - 1; i++)
        {
            
            if(nums[i] == k)
                return i;
        }
        return -1;
    }
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int > mp;
        int index = findK(nums, k);
        int n = nums.size(); 
        int count = 0;
        int greater = 0;
        int smaller = 0;
        mp[0] = 1;
        for(int i = 0; i<=n-1; i++)
        {
            if(nums[i] < k)
                smaller++;
            else if(nums[i] > k)
                greater++;
            
            if(i >= index)
            {
                count += mp[greater-smaller];
                count += mp[greater - smaller - 1];
            }
            
            if(i < index)
                mp[greater - smaller]++;
        }
            
        return count;
    }
};
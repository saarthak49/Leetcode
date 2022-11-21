class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0; 
        int j = nums.size() - 1;
        unordered_map<double, int> mp;
        while(i<j)
        {
            double avg = (nums[i++] + nums[j--]) / 2.0;
            mp[avg]++;
        }
        return mp.size();
    }
};
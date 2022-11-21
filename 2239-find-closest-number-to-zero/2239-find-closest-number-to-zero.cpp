class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = INT_MAX;
        int closest = -1;
        
        for(int i = 0; i<=nums.size() - 1; i++)
        {
            int newDist = abs(nums[i] - 0);
            if(newDist < dist)
            {
                closest = nums[i];
                dist = newDist;
            }
            else if(newDist == dist)
                closest = max(closest, nums[i]);
        }
        return closest;
    }
};
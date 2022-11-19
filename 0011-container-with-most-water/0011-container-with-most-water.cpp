class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int n = height.size();
        int j = n - 1;
        int maxWater = 0;
        while(i<j)
        {
            int waterStored = min(height[i], height[j]) * (j - i);
            maxWater = max(maxWater, waterStored);
            height[i]<height[j]?i++:j--;
        }
        return maxWater;
        
    }
};
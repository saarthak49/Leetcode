class Solution {
public:
    
    
    
    int trapFresh(vector<int> &height)
    {
        int lmax = INT_MIN;
        int rmax = INT_MIN;
        
        int n = height.size();
        int totalWater = 0;
        
        int i = 0;
        int j = n-1; 
        
        while(i<=j)
        {
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);
            if(lmax < rmax)
            {
                totalWater += lmax - height[i];
                i++;
            }
            else
            {
                totalWater += rmax - height[j];
                j--;
            }
        }
        return totalWater;
    }
    
    
    
    int trap(vector<int>& height) 
    {
        int lmax = 0;
        int rmax = 0;
        int i = 0;
        int j = height.size() - 1;
        int volume = 0;
        while( i <= j ) 
        {
            lmax = max(height[i], lmax);
            rmax = max(height[j], rmax);
            if( lmax < rmax )
            {
                volume += lmax - height[i++];
            }
            else if ( rmax < lmax)
            {
                volume += rmax - height[j--];
            }
            else
            {
                volume += lmax - height[i];
                if ( j != i ) {
                    volume += rmax - height[j];
                    j--;
                }
                i++;
            }
        }
        // return volume;
        return trapFresh(height);
        
    }
};
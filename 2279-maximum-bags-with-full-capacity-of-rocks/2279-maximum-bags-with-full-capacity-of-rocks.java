class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        
        
        int n = capacity.length;
        int[] rem = new int[n];
        
        for(int i = 0; i<=n-1; i++)
            rem[i] = capacity[i] - rocks[i];
        
        
        Arrays.sort(rem);
        int count = 0;
        for(int i = 0; i<=n-1 && additionalRocks > 0; i++)
        {
            if(rem[i] == 0)
                count++;
            else if(rem[i] > 0 && rem[i] <= additionalRocks)
            {
                count++;
                additionalRocks -= rem[i];
            }
        }
        
        return count;
        
        
    }
}
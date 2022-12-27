class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        
        
        int n = capacity.length;
        
        for(int i = 0; i<=n-1; i++)
            rocks[i] = capacity[i] - rocks[i];
        
        
        Arrays.sort(rocks);
        int count = 0;
        for(int i = 0; i<=n-1 && additionalRocks > 0; i++)
        {
            if(rocks[i] == 0)
                count++;
            else if(rocks[i] > 0 && rocks[i] <= additionalRocks)
            {
                count++;
                additionalRocks -= rocks[i];
            }
        }
        
        return count;
        
        
    }
}
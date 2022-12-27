class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        
        
        int n = capacity.length;
        
        for(int i = 0; i<=n-1; i++)
            rocks[i] = capacity[i] - rocks[i];
        
        
        Arrays.sort(rocks);
        int count = 0;
        for(int i = 0; i<=n-1; i++)
        {
            additionalRocks = additionalRocks - rocks[i];
            if(additionalRocks < 0)
                break;
            count = count + 1;
        }
        
        return count;
        
        
    }
}
class Solution {
    
    boolean canBeDone(int[] weights, int capacity, int days)
    {
        int day = 1;
        
        int n = weights.length;
        int sum = 0;
        int i = 0;
        while(i<=n-1)
        {
            sum += weights[i];
            if(weights[i] > capacity)
                return false;
            if(sum > capacity)
            {
                day++;
                sum = 0;
                i--;
            }
            i++;
        }
        if(day <= days)
            return true;
        return false;
    }
    
    public int shipWithinDays(int[] weights, int days) {
        
        int sum = 0;
        for(int weight: weights)
            sum += weight;
        
        int low = 0;
        int high = sum;
        
        int minCapacity = Integer.MAX_VALUE;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(canBeDone(weights, mid, days))
            {
                minCapacity = Math.min(minCapacity, mid);
                high = mid -1;
            }
            else
                low = mid + 1;
        }
        return minCapacity;
        
    }
}
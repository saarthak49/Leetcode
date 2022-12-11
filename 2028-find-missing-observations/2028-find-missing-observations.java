class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int sum = 0;
        for(int i : rolls)
            sum += i;
        
        
        sum = mean * (rolls.length + n) - sum;
        
        
        if(sum <= n * 6 && sum >= n)
        {
            int avg = sum / n;
            int remaining = sum % n;
            int[] ans = new int[n];
            for(int i = 0; i<=n-1; i++)
            {
                ans[i] = avg;
                if(remaining > 0)
                {
                    ans[i] += 1;
                    remaining--;
                }
            }
            return ans;
        }
        return new int[]{};
    }
}
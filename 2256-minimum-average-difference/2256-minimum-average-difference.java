class Solution {
    public int minimumAverageDifference(int[] nums) {
        List<Long> presum = new ArrayList<>();
        
        long sum = 0L;
        int n = nums.length;
        
        for(int i = 0; i<=n-1; i++)
        {
            sum+=(long)nums[i];
            presum.add(sum);
        }
        
        long minDiff = Long.MAX_VALUE;
        int index = -1;
        
        for(int i = 0; i<=n-1; i++)
        {
            long lsum = presum.get(i);
            long rsum = presum.get(n-1) - lsum;
            long nl = i + 1;
            long nr = n - i - 1;
            long la = 0;
            long ra = 0;
            
            la = lsum / nl;
            
            if(rsum != 0)
                ra = rsum / nr;
            
            // System.out.println(i + " " + lsum + " : " + nl + " : " + la + "    " + rsum + " : " + nr + " : " + ra);
            
            long diff = Math.abs(la - ra);
            if(diff < minDiff)
            {
                minDiff = diff;
                index = i;
            }
        }
        
        return index;
        
    }
}
class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        
        Queue<int[]> q = new PriorityQueue<>((int[] a, int[] b) -> {
            if(a[0] != b[0])
                return a[0] - b[0];
            return a[1] - b[1];
        });
        
        int n = costs.length;
        for(int i = 0; i<=candidates - 1; i++)
            q.offer(new int[]{costs[i], i});
        
        for(int i = n-1; i>=Math.max(candidates, n - candidates); i--)
            q.offer(new int[]{costs[i], i});
        
        int low = candidates;
        int high = n - candidates - 1;
        
        
        long sum = 0;
        while(k -- >  0)
        {
            int[] a = q.poll();
            sum+= a[0];
        
            if(high - low >= 0)
            {
                if(a[1] >= high)
                    q.offer(new int[]{costs[high], high--});
                else
                q.offer(new int[]{costs[low], low++});
            }
                
        }
        
        return sum;
    }
}
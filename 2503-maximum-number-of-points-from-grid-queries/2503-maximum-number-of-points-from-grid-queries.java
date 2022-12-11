class Solution {
    boolean isValid(int i, int j, int r, int c)
    {
        if(i>=0 && i<=r-1 && j<=c-1 && j>=0)
            return true;
        return false;
    }
    public int[] maxPoints(int[][] grid, int[] queries) {


        int[] x = {-1, 1, 0, 0};
        int[] y = {0, 0, 1, -1};

        List<int[]> nqueries = new ArrayList<>();

        int r = grid.length;
        int c = grid[0].length;
        int q = queries.length;
        for(int i = 0; i<=q-1; i++)
        {
            nqueries.add(new int[] {queries[i], i});
        }


        Collections.sort(nqueries, (int[] a, int[] b) -> {
            return a[0] - b[0];
        });

        int idx = 0;
        int count = 0;

        Queue<int[]> pq = new PriorityQueue<>((int[] a, int [] b) -> {
            return a[2] - b[2];
        });


        pq.offer(new int[] {0, 0, grid[0][0]});

        int[] ans = new int[q];
        
        grid[0][0] *= -1;


        while(idx <= q-1)
        {
            // System.out.println("Executing for the query " + nqueries.get(idx)[0]);
            if(!pq.isEmpty())
            {
                int[] cell = pq.poll();

                while(idx <= q-1 && cell[2] >= nqueries.get(idx)[0])
                {
                    ans[nqueries.get(idx)[1]] = count;
                    idx++;
                }
                
                
                if(idx >= q)
                break;
                
                count++;

                for(int ptr = 0; ptr<=3; ptr++)
                {
                    int nx = cell[0] + x[ptr];
                    int ny = cell[1] + y[ptr];

                    // greater than 0 means not visited
                    if(isValid(nx, ny, r, c) && grid[nx][ny] > 0) {
                        pq.offer(new int[] {nx, ny, grid[nx][ny]});
                        grid[nx][ny] *= -1;
                    }
                }
                ans[nqueries.get(idx)[1]] = count;
                continue;
            }
            // System.out.println("The queue became empty and now running for others");
            ans[nqueries.get(idx++)[1]] = count;
            
            // System.out.println("Currently executed for " + cell[0] + " : " + cell[1] + " with value " + cell[2]);

        }

        return ans;
    }
}
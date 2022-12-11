class Solution {
    boolean isValid(int i, int j, int r, int c)
    {
        if (i >= 0 && i <= r - 1 && j <= c - 1 && j >= 0)
            return true;
        return false;
    }

    public int[] maxPoints(int[][] grid, int[] queries) {
        int[] x = {-1, 1, 0, 0};
        int[] y = {0, 0, 1, -1};

        int[][] nqueries = new int[queries.length][2];

        int r = grid.length;
        int c = grid[0].length;
        int q = queries.length;
        for (int i = 0; i <= q - 1; i++) {
            nqueries[i][0] = queries[i];
            nqueries[i][1] = i;
        }

        Arrays.sort(nqueries, (int[] a, int[] b) -> a[0] - b[0]);

        int idx = 0;
        int count = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>((int[] a, int [] b) -> a[2] - b[2]);
        pq.offer(new int[]{0, 0, grid[0][0]});

        int[] ans = new int[q];
        grid[0][0] *= -1;

        while (idx <= q - 1) {
            if (pq.isEmpty()) {
                ans[nqueries[idx++][1]] = count;
                continue;
            }

            int[] cell = pq.poll();
            while (idx <= q - 1 && cell[2] >= nqueries[idx][0]) {
                ans[nqueries[idx][1]] = count;
                idx++;
            }

            if (idx >= q)
                break;

            count++;
            for (int i = 0; i < 4; i++) {
                int nx = cell[0] + x[i];
                int ny = cell[1] + y[i];

                if (!isValid(nx, ny, r, c) || grid[nx][ny] <= 0) {
                    continue;
                }

                pq.offer(new int[]{nx, ny, grid[nx][ny]});
                grid[nx][ny] *= -1;
            }
        }

        return ans;
    }
}

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (int[] a, int[] b) -> {
            if(a[0] != b[0])
                return a[0] - b[0];
            else
                return a[1] - b[1];
        });
        int arrows = 1;
        int n = points.length;
        for(int i = 1; i<=n-1; i++)
        {
            if(points[i][0] >= points[i-1][0] && points[i][0] <= points[i-1][1])
                points[i][1] = Math.min(points[i][1], points[i-1][1]);
            else
                arrows++;
        }
        return arrows;
    }
}
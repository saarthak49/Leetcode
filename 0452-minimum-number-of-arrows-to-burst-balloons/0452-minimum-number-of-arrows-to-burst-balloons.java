class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        int arrows = 1;
        int n = points.length;
        int last = points[0][1];
        for(int i = 1; i<=n-1; i++)
        {
            if(points[i][0] >= points[i-1][0] && points[i][0] <= last)
                last = Math.min(points[i][1], last);
            else
            {
                last = points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
}
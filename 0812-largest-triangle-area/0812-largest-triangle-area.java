class Solution {
    
    double getDeterminant(int x1, int x2, int y1, int y2)
    {
        return Math.abs((x1 * y2 - x2 * y1)/2.0);
    }
    public double largestTriangleArea(int[][] points) {
        double largestArea = 0;
        int n = points.length;
        for(int i = 0; i<=n-3; i++)
        {
            for(int j = i + 1; j<=n-2; j++)
            {
                for(int k = j + 1; k<=n-1; k++)
                {
                    int x1 = points[j][0] - points[i][0];
                    int x2 = points[k][0] - points[j][0];
                    
                    int y1 = points[j][1] - points[i][1];
                    int y2 = points[k][1] - points[j][1];
                    
                    largestArea = Math.max(largestArea, getDeterminant(x1, x2, y1, y2));
                }
            }
        }
        return largestArea;
    }
}
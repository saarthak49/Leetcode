class Point
{
    final int x;
    final int y;
    
    
    public Point()
    {
        x = 0;
        y = 0;
    }
    
    public Point(final int x, final int y)
    {
        this.x = x;
        this.y = y;
    }

    
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Point point)) return false;
        return x == point.x && y == point.y;
    }
    
    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
    
    @Override
    public String toString()
    {
        return this.x + " : " + this.y; 
    }
}




class Solution {
    
    public int findArea(Point p1, Point p2)
    {
        return Math.abs(p2.x - p1.x) * Math.abs(p2.y - p1.y);
    }
    
    
    public int minAreaRect(int[][] points) {
        int n = points.length;
        int minArea = Integer.MAX_VALUE;
        
        Map<Point, Integer> mp = new HashMap<>();
        
        for(int i = 0; i<=n-1; i++)
        {
            Point point = new Point(points[i][0], points[i][1]);
            
            mp.put(point, 1);
        }
        
        Point tempPoint = new Point(1, 3);
        
        for(int i = 0; i<=n-1; i++)
        {
            for(int j = i + 1; j<=n-1; j++)
            {
                Point p3 = new Point(points[i][0], points[j][1]);
                Point p4 = new Point(points[j][0], points[i][1]);
                
                if(mp.containsKey(p3) && mp.containsKey(p4))
                {
                    int area = findArea(p3, p4);
                    if(area > 0)
                        minArea = Math.min(area, minArea);
                }
            }
        }
        
        if(minArea == Integer.MAX_VALUE)
            return 0;
        return minArea;
    }
}
class Solution {
    
    private boolean inCircle(int x, int y, int radius, int xCenter, int yCenter)
    {
        int xc = xCenter - x;
        int yc = yCenter - y;
        
        if(xc * xc + yc * yc <= radius * radius)
            return true;
        return false;
    }
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int j = y1; j<=y2; j++)
        {
            if(inCircle(x1, j, radius, xCenter, yCenter))
                return true;
        }
        
        for(int j = y1; j<=y2; j++)
        {
            if(inCircle(x2, j, radius, xCenter, yCenter))
                return true;
        }
        
        for(int i = x1; i<=x2; i++)
        {
            if(inCircle(i, y1, radius, xCenter, yCenter))
                return true;
        }
        
        for(int i = x1; i<=x2; i++)
        {
            if(inCircle(i, y2, radius, xCenter, yCenter))
                return true;
        }
        
        if(xCenter >= x1 && yCenter >=y1 && xCenter<=x2 && yCenter <=y2)
            return true;
        
        return false;
    }
}
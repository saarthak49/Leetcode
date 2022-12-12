class Solution {
    public int hammingDistance(int x, int y) {
        
        int countdiff = 0;
        int i = 0;
        
        while(i<=30)
        {
            int mask = (int)Math.pow(2, i);
            if((x & mask ) != (y & mask))
                countdiff++;
            i++;
        }
        
        return countdiff;
        
    }
}
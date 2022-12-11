class Solution {
    public int minimumMoves(String s) {
        
        int n = s.length();
        int count = 0;
        
        
        int i = 0;
        while(i <= n-1)
        {
            if(s.charAt(i) == 'X')
            {
                count++;
                i+=3;
                continue;
            }
            i++;
        }
        
        return count;
    }
}
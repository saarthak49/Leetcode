class Solution {
    public int xorOperation(int n, int start) {
        int ans = 0;
        while(n --> 0)
            ans ^= start + 2 * n;
        return ans;
        
    }
}
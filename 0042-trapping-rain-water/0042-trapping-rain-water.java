class Solution {
    public int trap(int[] height) {
        int n = height.length;

        int i = 0;
        int j = n-1;

        int lmax = height[0];
        int rmax = height[n-1];

        int trappedWater = 0;
        while ( i<=j ) {
            lmax = Math.max(height[i], lmax);
            rmax = Math.max(height[j], rmax);

            if (lmax < rmax) {
                trappedWater += lmax - height[i];
                i++;
            }
            else {
                trappedWater += rmax - height[j];
                j--;
            }
        }
        return trappedWater;
    }
}
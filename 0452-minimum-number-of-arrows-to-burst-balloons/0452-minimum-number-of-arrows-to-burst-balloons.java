class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (int[] a, int[] b) -> {
            if(a[0] != b[0])
                return a[0] - b[0];
            else
                return a[1] - b[1];
        });
        Stack<int[]> st = new Stack<>();
        int arrows = 0;
        for(int[] a : points)
        {
            if(!st.isEmpty() && st.peek()[0] <= a[0] && st.peek()[1] >= a[0])
            {
                int[] b = st.pop();
                st.push(new int[]{a[0], Math.min(b[1], a[1])});
            }
            else
            {
                st.push(new int[]{a[0], a[1]});
                arrows++;
            }
        }
        return arrows;
    }
}
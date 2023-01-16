class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
         PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int x = newInterval[0], y = newInterval[1], len = intervals.length;
        for (int i = 0; i < len; i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if ((x<=l && l<=y) || (x<=r && r<=y) || ((l<=x && x<=r) && (l<=y && y<=r))){
                x = Math.min(x, l);
                y = Math.max(y, r);
            }
            else 
                q.add(intervals[i]);
        }
        q.add(new int[] { x, y });
        int size = q.size();
        int[][] res = new int[size][2];
        for (int i = 0; i < size; i++) {
            int t[] = q.remove();
            res[i] = t;
        }
        return res;
    }
}
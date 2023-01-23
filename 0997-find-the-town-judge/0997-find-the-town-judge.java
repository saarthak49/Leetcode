class Solution {
    public int findJudge(int n, int[][] trust) {
        Map<Integer, Integer> backward = new HashMap<>();
        Map<Integer, Integer> forward = new HashMap<>();
        for(int[] tr : trust)
        {
            int a = tr[0];
            int b = tr[1];
            backward.put(b, backward.getOrDefault(b, 0) + 1);
            forward.put(a, forward.getOrDefault(a, 0) + 1);
        }
        for(int i = 1; i<=n; i++)
        {
            if(backward.getOrDefault(i, 0) == n-1 && forward.getOrDefault(i, 0) == 0)
                return i;
        }
        return -1;
    }
}
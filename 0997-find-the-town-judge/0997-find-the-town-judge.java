class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] fw = new int[n+1];
        int[] bw = new int[n+1];
        for(int[] tr : trust)
        {
            int a = tr[0];
            int b = tr[1];
            fw[tr[1]]++;
            bw[tr[0]]++;
        }
        for(int i = 1; i<=n; i++)
        {
            if(fw[i] == n-1 && bw[i] == 0)
                return i;
        }
        return -1;
    }
}
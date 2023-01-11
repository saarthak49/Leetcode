class Solution {
    private static int time;
    public boolean getAnswer(int n, List<Integer>[] graph, List<Boolean> hasApple, int i, int parent)
    {
        boolean isApplePresent = false;
        for(int v : graph[i])
        {
            if(v != parent)
            {
                boolean ans = getAnswer(n, graph, hasApple, v, i);
                if(ans)
                    this.time += 2;
                isApplePresent = isApplePresent || ans;
            }
        }
        return isApplePresent || hasApple.get(i);
    }

    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        this.time = 0;
        List<Integer>[] graph = new ArrayList[n];
        for(int i = 0; i<=n-1; i++)
        {
            graph[i] = new ArrayList<>();
        }
        for(int edge[] : edges)
        {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        getAnswer(n, graph, hasApple, 0, -1);
        return this.time;
    }
}
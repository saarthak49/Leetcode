class Solution {
    
    
    
    public boolean runDfs(List<Integer> graph[], boolean vis[], int source, int destination)
    {
        if(source == destination)
            return true;
        
        vis[source] = true;
        
        for(int i : graph[source])
        {
            if(!vis[i])
            {
                if(runDfs(graph, vis, i, destination))
                    return true;
            }
        }
        return false;
    }
    
    
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        
        List<Integer>[] graph = new ArrayList[n + 1];
        for(int i = 0; i<=n; i++)
            graph[i] = new ArrayList<>();
        int s = edges.length;
        
        
        for(int edge[] : edges)
        {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        
        
        boolean[] vis = new boolean[n + 1];
        
        return runDfs(graph, vis, source, destination);
        
    }
}
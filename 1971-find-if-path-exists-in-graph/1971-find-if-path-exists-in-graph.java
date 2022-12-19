class Solution {
    
    
    
    public boolean runDfs(List<List<Integer> > graph, List<Boolean> vis, int source, int destination)
    {
        if(source == destination)
            return true;
        
        vis.set(source, true);
        
        for(int i : graph.get(source))
        {
            if(!vis.get(i))
            {
                if(runDfs(graph, vis, i, destination))
                    return true;
            }
        }
        return false;
    }
    
    
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        
        List<List<Integer> > graph = new ArrayList<>();
        for(int i = 0; i<=n; i++)
        {
            List<Integer> temp = new ArrayList<>();
            graph.add(temp);
        }
        
        int s = edges.length;
        for(int i = 0; i<=s - 1; i++)
        {
            int src = edges[i][0];
            int dst = edges[i][1];
            
            graph.get(src).add(dst);
            graph.get(dst).add(src);
        }
        
        List<Boolean> vis = new ArrayList<>();
        for(int i = 0; i<=n; i++)
            vis.add(false);
        
        
        return runDfs(graph, vis, source, destination);
        
    }
}
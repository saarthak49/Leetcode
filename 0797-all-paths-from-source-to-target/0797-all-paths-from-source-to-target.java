class Solution {
    
    
    
    public void runDfs(int source, int target, int[][] graph, List<List<Integer>> finalAns, List<Integer> pathSoFar, boolean vis[])
    {
        vis[source] = true;
        if(source == target)
        {
            List<Integer> path = new ArrayList(pathSoFar);
            path.add(source);  
            finalAns.add(path);
            vis[source] = false;
            return;
        }
        pathSoFar.add(source);
        for(int n : graph[source])
        {
            if(!vis[n])
                runDfs(n, target, graph, finalAns, pathSoFar, vis);
        }
        pathSoFar.remove(Integer.valueOf(source));
        vis[source] = false;
    }
    
    
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int source = 0;
        int target = graph.length - 1;
        List<List<Integer>> finalAns = new ArrayList<>();
        List<Integer> pathSoFar = new ArrayList<>();
        boolean vis[] = new boolean[target + 1];
        runDfs(source, target, graph, finalAns, pathSoFar, vis);
        return finalAns;
    }
}
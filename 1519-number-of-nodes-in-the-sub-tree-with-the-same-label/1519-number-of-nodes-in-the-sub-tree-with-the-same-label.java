class Solution {
    
    
    public int[] traverse(int i, int parent, List<Integer>[] graph, String labels, int[] finAns)
    {
        int[] ans = new int[26];
        ans[(char)(labels.charAt(i) - 'a')]++;
        for(int v : graph[i])
        {
            if(v != parent)
            {
                int[] arr = traverse(v, i, graph, labels, finAns);
                
                for(int j = 0; j<=25; j++)
                    ans[j] += arr[j];
            }
        }
        finAns[i] = ans[(char)(labels.charAt(i) - 'a')];
        return ans;
    }
    
    
    
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        int[] ans;
        int[] finAns = new int[n];
        List<Integer>[] graph = new ArrayList[n];
        for(int i = 0; i<=n-1; i++)
            graph[i] = new ArrayList<>();
        for(int[] edge : edges)
        {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        traverse(0, -1, graph, labels, finAns);
        return finAns;
    }
}
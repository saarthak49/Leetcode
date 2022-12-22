class Solution {
    
    public void dfs1(List<Integer>[] lst, int[] count, int i, int parent, int[] ans)
    {
        count[i] = 1;
        for(int n : lst[i])
        {
            if(n != parent)
            {
                dfs1(lst, count, n, i, ans);
                count[i] += count[n];
                ans[i] += ans[n] + count[n];
            }
        }
    }
    
    
    public void dfs2(List<Integer>[] lst, int[] count, int i, int parent, int[] ans)
    {
        for(int n : lst[i])
        {
            if(n != parent)
            {
                ans[n] = ans[i] - 2 * count[n] + count.length;
                dfs2(lst, count, n, i, ans);
            }
        }
    }
    
    
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        
        
        
        List<Integer>[] lst = new ArrayList[n];
        int[] count = new int[n];
        
        
        for(int i = 0; i<=n-1; i++)
            lst[i] = new ArrayList<>();
        
        
        
        for(int[] edge : edges)
        {
            lst[edge[0]].add(edge[1]);
            lst[edge[1]].add(edge[0]);
        }
        
        int[] ans = new int[n];
        dfs1(lst, count, 0, -1, ans);
        dfs2(lst, count, 0, -1, ans);
        
        return ans;
        
        
        
        
        
        
    }
}
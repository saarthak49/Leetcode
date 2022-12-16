class Solution {
    
    
    int[] parent;
    int[] rank;
    
    
    public int getParent(int i)
    {
        if(parent[i] == i)
            return i;
        parent[i] = getParent(parent[i]);
        return parent[i];
    }
    
    
    
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        parent = new int[n + 1];
        rank = new int[n + 1];
        
        
        for(int i = 0; i<=n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
        
        
        for(int i = 0; i<=n-1; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            int parA = getParent(a);
            int parB = getParent(b);
            
            if(parA == parB)
            {
                return new int[]{edges[i][0], edges[i][1]};
            }
            
            
            if(rank[parA] > rank[parB])
                parent[parB] = parA;
            else if(rank[parA] < rank[parB])
                parent[parA] = parB;
            else
            {
                parent[parB] = parA;
                rank[parA] += 1;
            }
        }
        
        return new int[]{-1, -1};
    }
}
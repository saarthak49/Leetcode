class TreeAncestor {
    
    
    private int[][] sparseTable;
    private int depth;

    public TreeAncestor(int n, int[] parent) {
        
        depth = (int)Math.floor(Math.log(n)/Math.log(2));
        
        sparseTable = new int[n][depth + 1];
        
        
        for(int j = 0; j<=depth; j++)
        {
            for(int i = 0; i<=n-1; i++)
            {
                
                if(j == 0)
                {
                    sparseTable[i][j] = parent[i];
                    continue;
                }
                
                
                
                if(sparseTable[i][j - 1] != -1)
                    sparseTable[i][j] = sparseTable[sparseTable[i][j-1]][j-1];
                else
                    sparseTable[i][j] = -1;
            }
        }
        
    }
    
    public int getKthAncestor(int node, int k) {
        
        if(node == 0)
            return -1;
        
        int ancestor = node;
        if((int)Math.floor(Math.log(k)/Math.log(2)) > depth)
            return -1;
        
        while(k >= 1 && ancestor != -1)
        {
            int colNumber = (int)Math.floor(Math.log(k)/Math.log(2));
            ancestor = this.sparseTable[ancestor][colNumber];
            k -= Math.pow(2, colNumber);
        }
        return ancestor;
    }
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor obj = new TreeAncestor(n, parent);
 * int param_1 = obj.getKthAncestor(node,k);
 */
class Solution {
    
    
    boolean col(List<Integer>[] lst, int node, int[] color, int lastColor)
    {
        
        // color the node as 1 if the lastColor is empty
        if(lastColor == 0)
            color[node] = 1;
        else if(lastColor == 1)
            color[node] = 2;
        else
            color[node] = 1;
        
        
        
        
        
        lastColor = color[node];
        int expectedColor = color[node] == 1 ? 2 : 1;
        
        
        
        
        for(int person : lst[node])
        {
            if(color[person] != 0 && color[person] != expectedColor)
                return false;
            
            else if(color[person] == 0)
            {
                boolean result = col(lst, person, color, lastColor);
                if(!result)
                    return false;
            }
        }
        return true;
    }
    
    
    
    
    
    public boolean possibleBipartition(int n, int[][] dislikes) {
        
        
        
        
        List<Integer>[] lst = new ArrayList[n + 1];
        
        
        // initialize the graph
        for(int i = 1; i<=n; i++)
            lst[i] = new ArrayList<>();
        
        
        // build the graph
        for(int[] dislike : dislikes)
        {
            lst[dislike[0]].add(dislike[1]);
            lst[dislike[1]].add(dislike[0]);
        }
        
        
        
        
        int[] color = new int[n + 1];
        
        for(int i = 1; i<=n; i++)
        {
            if(color[i] == 0)
            {
                boolean answer = col(lst, i, color, 0);
                if(!answer)
                    return false;
            }
        }
        
        return true;
    }
}
class Solution {
    
    
    int getParent(List<Integer> dsu, int i)
    {
        if(dsu.get(i) == -1)
            return -1;
        
        
        if(dsu.get(i) == i)
            return i;
        
        return getParent(dsu, dsu.get(i));
    }
    
    void union(List<Integer> dsu, int var1, int var2)
    {
        int par1 = getParent(dsu, var1);
        int par2 = getParent(dsu, var2);
        if(par1 == -1)
        {
            dsu.set(var1, var1);
            par1 = var1;
        }
        if(par2 == -1) {
            dsu.set(var2, var2);
            par2 = var2;
        }
        
        
        
        if(par1 != par2)
            dsu.set(par1, par2);
    }
    
    boolean inequality(List<Integer> dsu, int var1, int var2)
    {
        if(var1 == var2)
            return false;
        int par1 = getParent(dsu, var1);
        if(par1 == -1)
        {
            dsu.set(var1, var1);
            par1 = var1;
        }
        int par2 = getParent(dsu, var2);
        if(par2 == -1)
        {
            dsu.set(var2, var2);
            par2 = var2;
        }
        
        
    
        if(par1 == par2)
            return false;
        
        return true;
    }
    
    
    public boolean equationsPossible(String[] equations) {
        List<Integer> dsu = new ArrayList<>();
        
        int n = equations.length;
        
        for(int i = 0; i<=25; i++)
            dsu.add(-1);
        
        
        for(int i = 0; i<=n-1; i++)
        {
            int var1 = (int) (equations[i].charAt(0) - 'a');
            int var2 = (int) (equations[i].charAt(3) - 'a');
            if(equations[i].charAt(1) == equations[i].charAt(2))
                union(dsu, var1, var2);
        }
        
        for(int i = 0; i<=n-1; i++)
        {
            int var1 = (int) (equations[i].charAt(0) - 'a');
            int var2 = (int) (equations[i].charAt(3) - 'a');
            if(equations[i].charAt(1) != equations[i].charAt(2))
            {
                
                if(!inequality(dsu, var1, var2))
                    return false;
            }
        }
        return true;
        
    }
}
class Store
{
    int last;
    Set<Integer> used;
    
    
    public Store(int last, Set<Integer> used)
    {
        this.last = last;
        this.used = used;
    }
    
}


class Solution {
    
    
    public String[] getFolderNames(String[] names) {
        
        
        Map<String, Integer> mp = new HashMap<>();
        int n = names.length;
        
        for(int i = 0; i<=n-1; i++)
        {
            String str = names[i];
            if(mp.containsKey(str))
            {
                int lastVal = mp.get(str);
                int nval = lastVal + 1;
                String nstr = str + "(" + nval + ")";
                while(mp.containsKey(nstr))
                {
                    nval++;
                    nstr = str + "(" + nval + ")";
                }
                
                mp.put(nstr, 0);
                
            
                mp.put(str, nval);
                names[i] = nstr;
            }
            else
            {
                mp.put(str, 0);
            }
        }
        
        return names;
        
        
        
    }
}
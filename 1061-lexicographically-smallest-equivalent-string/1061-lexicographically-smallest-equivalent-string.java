class Solution {
    
    
    private int[] parent;
    
    public int getParent(int ch)
    {
        if(this.parent[ch] == -1)
            return ch;
        parent[ch] = getParent(parent[ch]);
        return parent[ch];
    }
    
    
    
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        this.parent = new int[26];
        for(int i = 0; i<=25; i++)
            parent[i] = -1;
        int n = s1.length();
        for(int i = 0; i<=n-1; i++)
        {
            int p1 = getParent((int)(s1.charAt(i) - 'a'));
            int p2 = getParent((int)(s2.charAt(i) - 'a'));
            if(p1 < p2)
                this.parent[p2] = p1;
            else if(p1 > p2)
                this.parent[p1] = p2;
        }
        String finAns = "";
        n = baseStr.length();
        for(int i = 0; i<=n-1; i++)
        {
            finAns += (char)(getParent(baseStr.charAt(i) - 'a') + 'a');
        }
        return finAns;
    }
}
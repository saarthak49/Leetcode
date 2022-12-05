class Solution {
    public boolean closeStrings(String word1, String word2) {
        
        
        int n1 = word1.length();
        int n2 = word2.length();
        
        if(n1 != n2)
            return false;
        
       
        
        
        int[] freq1 = new int[27];
        int[] freq2 = new int[27];
        
        List<Integer> lst1 = new ArrayList<>();
        List<Integer> lst2 = new ArrayList<>();
        
        for(int i = 0; i<=n1-1; i++)
        {
            int index = (int)(word1.charAt(i) - 'a');
            freq1[index]++;
        }
        for(int i = 0; i<=n2-1; i++)
        {
            int index = (int)(word2.charAt(i) - 'a');
            freq2[index]++;
        }
        
        for(int i = 0; i<=25; i++)
        {
            if(freq1[i] != 0 && freq2[i] == 0)
                return false;
            if(freq1[i] != 0)
            lst1.add(freq1[i]);
            if(freq2[i] != 0)
            lst2.add(freq2[i]);
        }
        Collections.sort(lst1);
        Collections.sort(lst2);
        if(lst1.size() != lst2.size())
            return false;
        
        // System.out.println(lst1);
        // System.out.println(lst2);
        
        for(int i = 0; i<=lst1.size()-1 && i<=lst2.size()-1; i++)
        {
            if((int)lst1.get(i) != (int)lst2.get(i))
            {
                // System.out.println("mismatch found " + lst1.get(i) + " : " + lst2.get(i));
                return false;
            }
        }
        return true;
        
    }
}
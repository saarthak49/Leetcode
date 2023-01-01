class Solution {
    public boolean wordPattern(String pattern, String s) {
        
        
        
        int i = 0;
        int j = 0;
        int count = 0;
        
        
        int n = pattern.length();
        int m = s.length();
        
        
        Map<Character, String> forward = new HashMap<>();
        Map<String, Character> backward = new HashMap<>();
        
        
        
        while(i <= n-1 && j <= m-1)
        {
            
            String str = "";
            
            if(s.charAt(j) == ' ')
                j++;
            
            
            while(j<=m-1 && s.charAt(j) != ' ')
                str += s.charAt(j++);
            
            
            if(forward.containsKey(pattern.charAt(i)) && backward.containsKey(str))
            {
                if(!(forward.get(pattern.charAt(i)).equals(str) && backward.get(str).equals(pattern.charAt(i))))
                    return false;
            }
            else if(!forward.containsKey(pattern.charAt(i)) && !backward.containsKey(str))
            {
                forward.put(pattern.charAt(i), str);
                backward.put(str, pattern.charAt(i));
            }
            else
            {
                return false;
            }
            i++;
        }
        
        if(i == n && j != m)
            return false;
        else if(i != n && j == m)
            return false;
        return true;
    }
}
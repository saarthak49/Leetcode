class Solution {
    public String removeOccurrences(String s, String part) {
        
        
        Stack<Character> st = new Stack<>();
        
        
        int n = s.length();
        int m = part.length();
        
        StringBuilder st1 = new StringBuilder("");
        
        int index = 0;
        
        
        for(int i = 0; i<=n-1; i++)
        {
            if(st1.length() < (i + 1))
                st1.append("a");
            st1.append(s.charAt(i));
            st1.setCharAt(index, s.charAt(i));
            
            int j = m - 1;
            int temp = index;
            while(j >= 0 && temp >=0 && st1.charAt(temp) == part.charAt(j))
            {
                temp--;
                j--;
            }
            if(j == -1)
                index = temp;
            
            index++;
        }
        return st1.substring(0, index);
    }
}
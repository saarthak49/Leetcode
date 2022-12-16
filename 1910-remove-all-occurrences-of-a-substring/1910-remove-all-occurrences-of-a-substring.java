class Solution {
    public String removeOccurrences(String s, String part) {
        
        
        Stack<Character> st = new Stack<>();
        
        
        int n = s.length();
        int m = part.length();
        
        for(int i = 0; i<=n-1; i++)
        {
            st.add(s.charAt(i));
            
            int j = m - 1;
            Stack<Character> temp = new Stack<>();
            while(j >= 0 && !st.isEmpty() && st.peek() == part.charAt(j))
            {
                temp.add(st.pop());
                j--;
            }
            if(j != -1)
            {
                while(!temp.isEmpty())
                    st.add(temp.pop());
            }
        }
        StringBuilder str = new StringBuilder("");
        
        while(!st.isEmpty())
        {
            str.append(st.pop());
        }
        
        return String.valueOf(str.reverse());
        
        
    }
}
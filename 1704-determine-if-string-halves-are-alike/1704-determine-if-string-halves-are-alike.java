class Solution {
    public boolean halvesAreAlike(String s) {
        int n = s.length();
        int i = 0;
        int j = n / 2;
        
        int count1 = 0;
        int count2 = 0;
        
        while(j<=n-1)
        {
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I' || s.charAt(i) == 'O' || s.charAt(i) == 'U')
                count1++;
            
            if(s.charAt(j) == 'a' || s.charAt(j) == 'e' || s.charAt(j) == 'i' || s.charAt(j) == 'o' || s.charAt(j) == 'u' || s.charAt(j) == 'A' || s.charAt(j) == 'E' || s.charAt(j) == 'I' || s.charAt(j) == 'O' || s.charAt(j) == 'U')
                count2++;
            
            i++;
            j++;
        }
        
        if(count1 == count2)
            return true;
        return false;
        
        
        
    }
}
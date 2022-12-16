class Solution {
    public int maximum69Number (int num) {
        
        
        String s = String.valueOf(num);
        
        StringBuilder str = new StringBuilder(s);
        int n = str.length();
        
        for(int i = 0; i<=n-1; i++)
        {
            if(str.charAt(i) == '6')
            {
                str.setCharAt(i, '9');
                break;
            }
        }
        return Integer.parseInt(String.valueOf(str));
        
        
    }
}
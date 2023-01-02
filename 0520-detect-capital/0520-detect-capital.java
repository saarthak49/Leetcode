class Solution {
    public boolean detectCapitalUse(String word) {
        int n = word.length();
        int count = 0;
        boolean firstCapital = word.charAt(0) >= 'A' && word.charAt(0) <= 'Z';
        for(int i = 0; i<=n-1; i++)
        {
            if(word.charAt(i) >= 'A' && word.charAt(i) <= 'Z')
                count++;
        }
        return (firstCapital && count == 1 || count == n || count == 0);
    }
}
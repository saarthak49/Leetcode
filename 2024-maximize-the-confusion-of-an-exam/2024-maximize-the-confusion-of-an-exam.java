class Solution {
    
    
    public int count(String answerKey, int k, char ch)
    {
        
        
        int capacity = k;
        int n = answerKey.length();
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while(j <= n-1)
        {
            int len = 0;
            if(answerKey.charAt(j) == ch)
            {
                maxLen = Math.max(maxLen, j - i + 1);
                j++;
            }
            else
            {
                if(capacity > 0)
                {
                    capacity--;
                    maxLen = Math.max(maxLen, j - i + 1);
                    j++;
                }
                else
                {
                    if(answerKey.charAt(i) != ch)
                        capacity++;
                    i++;
                }
            }
        }
        
        return maxLen;
    }
    
    
    
    public int maxConsecutiveAnswers(String answerKey, int k) {
        
        
        return Math.max(count(answerKey, k, 'T'), count(answerKey, k, 'F'));
        
    }
}
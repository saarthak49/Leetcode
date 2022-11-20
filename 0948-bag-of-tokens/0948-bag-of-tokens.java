class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int n = tokens.length;
        
        Arrays.sort(tokens, 0, n);
        
        int i = 0;
        int score = 0;
        int maxScore = 0;
        int j = n - 1;
        while(i<=j)
        {
            if(power >= tokens[i])
            {
                power -= tokens[i++];
                score++;
                maxScore = Math.max(score, maxScore);
            }
            else if(score >= 1)
            {
                power += tokens[j--];
                score--;
            }
            else if(score == 0)
                break;
        }
        return maxScore;
        
    }
}
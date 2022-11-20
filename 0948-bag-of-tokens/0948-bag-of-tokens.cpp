class Solution {
public:
    
    
    
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        if(tokens.size() == 0)
            return 0;
        
        
        sort(tokens.begin(), tokens.end());
        int i = 0; 
        int j = tokens.size() - 1;
        int maxScore = 0;
        int score = 0;
        while(i<=j)
        {
            if(i<=j && power>=tokens[i])
            {
                power -= tokens[i++];
                score++;
                maxScore = max(score, maxScore);
            }
            else if(i<=j && power<tokens[i] && score >= 1)
            {
                power += tokens[j--];
                score--;
            }
            else if(score == 0 && power < tokens[i])
                break;
        }
        return maxScore;
        
    }
};
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0; 
        int j = tokens.size() - 1;
        int maxScore = 0;
        int score = 0;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power -= tokens[i++];
                score++;
                maxScore = max(score, maxScore);
            }
            else if(score >= 1)
            {
                power += tokens[j--];
                score--;
            }
            else
                return maxScore;
        }
        return maxScore;
    }
};
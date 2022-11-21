class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if(suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4])
            return "Flush";
        for(int i = 0; i<=2; i++)
        {
            for(int j = i+1; j<=3; j++)
            {
                for(int k= j+1; k<=4; k++)
                {
                    if(ranks[i] == ranks[j] && ranks[j] == ranks[k])
                        return "Three of a Kind";
                }
            }
        }
        
        for(int i = 0; i<=3; i++)
        {
            for(int j = i+1; j<=4; j++)
            {
                if(ranks[i] == ranks[j])
                    return "Pair";
            }
        }
        
        return "High Card";
        
    }
};
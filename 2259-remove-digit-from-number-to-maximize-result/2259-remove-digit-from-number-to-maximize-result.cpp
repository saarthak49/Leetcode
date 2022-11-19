class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        
        // int maxSeen = 0;
        string finalAnswer = "0";
        
        for(int i = 0; i<=n-1; i++)
        {
            if(number[i] == digit)
            {
                string str1 = number.substr(0, i);
                string str2 = number.substr(i + 1);
                
                string finalString = str1 + str2;
                
                if(finalString > finalAnswer)
                {
                    finalAnswer = finalString;
                }
            }
        }
        
        return finalAnswer;
        
    }
};
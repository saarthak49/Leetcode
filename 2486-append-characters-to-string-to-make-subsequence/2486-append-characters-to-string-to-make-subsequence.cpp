class Solution {
public:
    
    
    int findLcs(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<int> lastState(n + 1, 0);
        for(int i = 0; i<=n-1; i++)
        {
            if(t[0] == s[i])
                lastState[i + 1] = 1;
            else 
                lastState[i + 1] = lastState[i];
        }
        for(int i = 1; i<=n; i++)
            cout<<lastState[i]<<" ";
        cout<<endl;
        vector<int> currState(n + 1, 0);
        
        for(int j = 0; j<=m-1; j++)
        {
            for(int i = 0; i<=n-1; i++)
            {
                if(s[i] == t[j])
                {
                    currState[i + 1] = max(currState[i], lastState[i + 1]) + 1;
                }
                else
                    currState[i + 1] = max(currState[i], lastState[i + 1]);
            }
            lastState = currState;
            for(int i = 1; i<=n; i++)
                cout<<lastState[i]<<" ";
            cout<<endl;
        }
        return currState[n];
    }
    
    
    int appendCharacters(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        while(i<=n-1 && j <= m-1)
        {
            if(s[i] != t[j])
                i++;
            else
            {
                i++;
                j++;
            }
        }
        return m - j;
  
    
    }
};


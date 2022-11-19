class Solution {
public:
    
    unordered_map<string, int> mp;
    vector<string> output;
    
    int getMinimumNumberOfRemovalsToMakeValid(string &str)
    {
        stack<char> s;
        int n = str.size();
        for(int i = 0; i<=n-1; i++)
        {
            if(str[i] == '(')
                s.push('(');
            else if(str[i] == ')')
            {
                if(s.empty())
                    s.push(')');
                else
                {
                    char t = s.top();
                    if(t == '(')
                        s.pop();
                    else
                        s.push(')');
                }
            }
        }
        return s.size();
    }
    
    
    void solve(string str, int minimumRemovals)
    {
        if(mp[str] != 0)
            return;
        else
            mp[str] = 1;
        if(minimumRemovals == 0)
        {
            if(getMinimumNumberOfRemovalsToMakeValid(str) == 0)
            {
                output.push_back(str);
            }
        }
        
        
        int n = str.size();
        for(int i = 0; i<=n-1; i++)
        {
            if(str[i] == '(' || str[i] == ')')
            {
                string newString = str.substr(0, i) + str.substr(i + 1);
                solve(newString, minimumRemovals - 1);
            }
        }
    }
    
    
    
    
    vector<string> removeInvalidParentheses(string s) {
        
        solve(s, getMinimumNumberOfRemovalsToMakeValid(s));
        return output;
        
    }
};
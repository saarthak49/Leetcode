class Solution {
public:
    
    unordered_map<string, int> mp;
    
    int getMinimumNumberOfRemovalsToMakeValid(string str)
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
    
    
    void solve(string str, int minimumRemovals, vector<string> &output)
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
                solve(newString, minimumRemovals - 1, output);
            }
        }
    }
    
    
    
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string, int> mp;
        int minimumRemovals = getMinimumNumberOfRemovalsToMakeValid(s);
        // cout<<minimumRemovals<<endl;
        vector<string> output;
        solve(s, minimumRemovals, output);
        
        
        
        
        return output;
        
    }
    
    // unordered_map<string,int> mp;
    // int getMinValid(string s)
    // {
    //     stack<char> st;
    //     int i=0;
    //     while(i < s.size())
    //     {
    //         if(s[i]=='(')
    //             st.push(s[i]);
    //         else if(s[i]==')')
    //         {
    //             if(st.size()>0 && st.top()=='(')
    //                 st.pop();
    //             else
    //                 st.push(s[i]);
    //         }
    //         i++;    
    //     }
    //     return st.size();
    // }
    // void solve(string s,int mr,vector<string> &res)
    // {
    //     if(mp[s]!=0)
    //         return;
    //     else
    //         mp[s]++;
    //     if(mr==0)
    //     {
    //         if(getMinValid(s)==0)
    //         {
    //            res.push_back(s); 
    //         }
    //     }
    //     for(int i=0;i<s.size();i++)
    //     {
    //         string left=s.substr(0,i);
    //         string right=s.substr(i+1);
    //         solve(left+right,mr-1,res);
    //     }
    // }
    // vector<string> removeInvalidParentheses(string s) {
    //     vector<string> res;
    //     solve(s,getMinValid(s),res);
    //     return res;
    // }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i<=s.size()-1; i++)
        {
            if(s[i] == '(')
                st.push('(');
            else if(s[i] == '{')
                st.push('{');
            else if(s[i] == '[')
                st.push('[');
            else if(s[i] == ')')
            {
                if(!st.empty() && st.top() == '(' )
                    st.pop();
                else
                    st.push(')');
            }
            else if(s[i] == '}')
            {
                if(!st.empty() && st.top() == '{' )
                    st.pop();
                else
                    st.push('}');
            }
            else if(s[i] == ']')
            {
                if(!st.empty() && st.top() == '[' )
                    st.pop();
                else
                    st.push(']');
            }
        }
        return st.size() == 0 ;
            
    }
};
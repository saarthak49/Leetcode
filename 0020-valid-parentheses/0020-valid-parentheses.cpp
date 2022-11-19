class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<=s.size()-1; i++)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    st.push(s[i]);
                    break;
                case ')':
                    if(!st.empty() && st.top() == '(')
                        st.pop();
                    else
                        st.push(s[i]);
                    break;
                case '}':
                    if(!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        st.push(s[i]);
                    break;
                case ']':
                    if(!st.empty() && st.top() == '[')
                        st.pop();
                    else
                        st.push(s[i]);
            }
        }
        return st.size() == 0 ;
    }
};
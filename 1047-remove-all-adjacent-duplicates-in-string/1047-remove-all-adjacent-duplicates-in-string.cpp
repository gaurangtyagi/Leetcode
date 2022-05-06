class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st; 
        for (int i = 0; i<s.length(); i++)
        {
            if (!st.empty())
            {
                if (st.top() == s[i])
                {
                    st.pop();
                }
                else 
                {
                    st.push(s[i]);
                }
            }
            else 
            {
                st.push(s[i]);
            }
        }
        
        string p = "";
        while (!st.empty())
        {
            p += st.top();
            st.pop();
        }
        reverse(p.begin(), p.end());
        return p;
    }
};
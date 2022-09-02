class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> st; 
        for (int i = 0; i<s.length(); i++)
        {
            if (s[i] == '*' && !st.empty()) st.pop();
            else if (s[i] != '*') st.push(s[i]);
        }
        string t= "";
        int size = st.size();
        for (int i = 0; i<size; i++)
        {
            t += st.top();
            st.pop();
        }
        reverse(t.begin(), t.end());
        return t;
    }
};
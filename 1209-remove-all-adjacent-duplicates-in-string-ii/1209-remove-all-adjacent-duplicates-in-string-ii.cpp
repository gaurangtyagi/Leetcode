class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char, int>> st; 
        for (int i = 0; i<s.length(); i++)
        {
            if (!st.empty())
            {
                if (st.top().first != s[i])
                {
                    char x = s[i];
                    int count = 1;
                    st.push({ x, count });
                } 
                else
                {
                    st.top().second ++;
                    
                    if (st.top().second == k)
                    {
                        st.pop();
                    }
                }
            }
            else 
            {
                st.push({s[i], 1});
            }
            
        }
        string p = "";
        while(!st.empty())
        {
            while(st.top().second != 0)
            {
                p += st.top().first;
                st.top().second--;
            }
            st.pop();
        }
        reverse(p.begin(), p.end());
        return p;

    }
};
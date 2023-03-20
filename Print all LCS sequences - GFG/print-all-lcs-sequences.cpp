//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string> st;
	vector<string> ans; 
	    void helper(int i, int j, string s, string t, int len, string temp)
	    {
	        if (len == 0)
	        {
	            if (st.find(temp) == st.end())
	            {
	                ans.push_back(temp);
	                st.insert(temp);
	            }
	            return; 
	        }
	        if (i >= s.size() || j >= t.size()) return; 
	        for (int row = i; row < s.size(); row++)
	        {
	            for (int col = j; col < t.size(); col++)
	            {
	                if (s[row] == t[col])
	                {
	                    temp.push_back(s[row]);
	                    helper(row + 1, col + 1, s, t, len - 1, temp);
	                    temp.pop_back();
	                }
	            }
	        }
	    }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    // first find length of lcs then print lcs
		    int n = s.length();
		    int m = t.length();
		    int dp[n + 1][m + 1];
		    memset(dp , 0, sizeof(dp));
		    for (int i = 1; i<= n; i++)
		    {
		        for (int j = 1; j<= m; j++)
		        {
		            if (s[i-1] == t[j-1])
		            {
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else 
		            {
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    int len = dp[n][m]; // length of lcs
		    helper(0, 0, s, t, len, "");
		    sort(ans.begin(), ans.end());
		    return ans; 
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends
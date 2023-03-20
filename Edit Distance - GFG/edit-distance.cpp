//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        // convert s to t
        int dp[n + 1][m + 1];
        memset(dp , 0, sizeof(dp));
        for (int i = 0; i<= n; i++)
        {
            dp[i][0] = i; 
            // if string t is null then how many steps will it take to convert from s to t
            // number of steps = number of deletion = size of string s;
        }
        for (int j = 0; j<= m; j++)
        {
            dp[0][j] = j; 
            // same as above
        }
        for (int i = 1; i<= n; i++)
        {
            for (int j = 1; j<= m; j++)
            {
                if (s[i-1] == t[j-1])
                {
                    // if the current character is same in both the strings then we need not to perform any operation to convert s[i] -> t[j]
                    dp[i][j] = dp[i-1][j-1];
                }
                else 
                {
                    // else we have 3 operation
                    // addition and deletion --> 
                    // dp[i-1][j] and dp[i][j-1]
                    // replace 
                    // dp[i-1][j-1]
                    // we choose minimum of these operation then add 1 to it 
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1; 
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
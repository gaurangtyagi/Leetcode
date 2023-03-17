//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int LCS(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n + 1][m + 1]; 
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<= n; i++)
        {
            for (int j = 1; j<= m; j++)
            {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];    
    }
    int longestPalinSubseq(string A) {
        //code here
        string B = A; 
        reverse(A.begin(), A.end());
        return LCS(A, B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
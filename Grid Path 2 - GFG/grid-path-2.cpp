//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int totalWays(int a, int b, vector<vector<int>>& ar) {
        // Code here
        vector<vector<int>> dp(a, vector<int> (b, 0));
        for (int i = 0; i<a; i++)
        {
            if (ar[i][0]) break;
            dp[i][0] = 1; 
             
        }
        for (int j = 0; j<b; j++)
        {
            if (ar[0][j]) break;
            dp[0][j] = 1; 
             
        }
        for (int i = 1; i<a; i++)
        {
            for (int j = 1; j<b; j++)
            {
                if (!ar[i][j]) dp[i][j] = (dp[i-1][j]%1000000007 + dp[i][j-1]%1000000007)%1000000007;
                else dp[i][j] = 0; 
                
            }
        }
        return dp[a-1][b-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &a) {
        // code here
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for (int i = 0; i<n; i++)
        {
            if (a[i][0] == 1) dp[i][0] = 1; 
            else break; 
        }
        for (int j = 0; j<m; j++)
        {
            if (a[0][j] == 1) dp[0][j] = 1; 
            else break; 
        }
        for (int i = 1; i<n; i++)
        {
            for (int j = 1; j<m; j++)
            {
                if (a[i][j])
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
                    dp[i][j] %= 1000000007; 
                }
                else dp[i][j] = 0; 
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& t) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        dp[0][0] = t[0][0];
        for (int i = 1; i<n; i++)
        {
            for (int j = 0; j<i + 1; j++)
            {
                if (j) dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + t[i][j];
                else dp[i][j] = t[i][j] + dp[i-1][j];
            }
        }
        int ans = INT_MAX; 
        for (int i = 0; i<n; i++)
        {
            ans = min(ans, dp[n-1][i]);
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends
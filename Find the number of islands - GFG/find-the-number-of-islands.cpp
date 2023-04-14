//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, int n, int m, vector<vector<char>> &a)
    {
        if (i >= n || j>= m) return; 
        if (i < 0 || j < 0) return; 
        if (a[i][j] == '0') return;
        a[i][j] = '0';
        dfs(i + 1, j, n, m, a); // up
        dfs(i - 1, j, n, m, a); // down
        dfs(i + 1, j + 1, n, m, a); // diag
        dfs(i + 1, j - 1, n, m, a); // diag
        dfs(i - 1, j + 1, n, m, a); // diag
        dfs(i - 1, j - 1, n, m, a); // diag
        dfs(i, j + 1, n, m, a); // right
        dfs(i, j - 1, n, m, a); // left
    }
    int numIslands(vector<vector<char>>& a) {
        // Code here
        int n = a.size();
        int m = a[0].size();
        int ans = 0; 
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m;j++)
            {
                if (a[i][j] == '1')
                {
                    ans++; 
                    dfs(i, j, n, m, a);
                }
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &a, vector<pair<int, int>> &x)
    {
        vis[i][j] = true; 
        x.push_back({i, j});
        if (i && a[i-1][j] && !vis[i-1][j]) dfs(i-1, j, n, m, vis, a, x);
        if (j && a[i][j-1] && !vis[i][j-1]) dfs(i, j-1, n, m, vis, a, x);
        if (i<n-1 && a[i+1][j] && !vis[i+1][j]) dfs(i+1, j, n, m, vis, a, x);
        if (j<m-1 && a[i][j+1] && !vis[i][j+1]) dfs(i, j+1, n, m, vis, a, x);
    }
    int countDistinctIslands(vector<vector<int>>& a) {
        // code here
        int n = a.size();
        int m = a[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        set<vector<pair<int, int>>> s; 
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j< m; j++)
            {
                if (!vis[i][j] && a[i][j])
                {
                    vector<pair<int, int>> x; 
                    dfs(i, j, n, m, vis, a, x);
                    int a = x[0].first;
                    int b = x[0].second; 
                    for (int i = 0; i<x.size(); i++)
                    {
                        x[i].first -= a; 
                        x[i].second -= b; 
                    }
                    s.insert(x);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
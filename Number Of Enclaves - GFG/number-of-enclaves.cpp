//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i, int j, vector<vector<int>>& a, int n, int m)
    {
        a[i][j] = 2; 
        if (i && a[i-1][j] == 1)
        {
            dfs(i-1, j, a, n, m);
        }
        if (j && a[i][j - 1] == 1)
        {
            dfs(i, j - 1, a, n, m);
        }
        if (j < m-1 && a[i][j + 1] == 1)
        {
            dfs(i, j + 1, a, n, m);
        }
        if (i < n-1 && a[i+1][j] == 1)
        {
            dfs(i+1, j, a, n, m);
        }
    } 
    int numberOfEnclaves(vector<vector<int>> &a) {
        int n = a.size();
        int m = a[0].size();
        int count = 0; 
        
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (a[i][j] == 1)
                {
                    if (!i || !j || i == n-1 || j == m-1)
                    {
                        dfs(i, j, a, n, m);
                    }
                }
            }
        }
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (a[i][j] == 1) count++; 
            }
        }
        return count; 
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
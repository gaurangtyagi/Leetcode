//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>& a, int n, int m, vector<vector<bool>>& vis)
    {
        vis[i][j] = true; 
        a[i][j] = '#';
        if (i && a[i-1][j] =='O')
        {
            dfs(i-1, j, a, n, m, vis);
        }
        if (j && a[i][j - 1] =='O')
        {
            dfs(i, j - 1, a, n, m, vis);
        }
        if (j < m-1 && a[i][j + 1] =='O')
        {
            dfs(i, j + 1, a, n, m, vis);
        }
        if (i < n-1 && a[i+1][j] =='O')
        {
            dfs(i+1, j, a, n, m, vis);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> a)
    {
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (!i || !j || i == n-1 || j == m-1)
                {
                    if (a[i][j] == 'O' && !vis[i][j])
                    {
                        dfs(i, j, a, n, m, vis);
                    }
                }
            }
        }
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
            {
                if (a[i][j] == 'O') a[i][j] = 'X';
                if (a[i][j] == '#') a[i][j] = 'O';
            }
        }
        return a; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
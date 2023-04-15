//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path, vector<bool> &check)
    {
        vis[node] = 1; 
        path[node] = 1; 
        check[node] = 0; 
        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, adj, vis, path, check))
                {
                    return true;
                }
            }
            else 
            {
                if (path[it])
                {
                    
                    return true; 
                }
            }
        }
        path[node] = 0; 
        check[node] = 1; 
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans; 
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        vector<bool> check(V, false);
        for (int i = 0; i<V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, path, check);
            }
        }
        for (int i = 0; i<V; i++)
        {
            if (check[i]) ans.push_back(i);
        }
        return ans; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
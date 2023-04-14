//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node, vector<int> adj[], bool vis[], int V)
    {
        vis[node] = 1; 
        queue<pair<int, int>> q; 
        q.push({node, -1});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            for (auto ids : adj[it.first])
            {
                if (!vis[ids])
                {
                    vis[ids] = 1; 
                    q.push({ids, it.first});
                }
                else 
                {
                    if (ids != it.second) return true; 
                }
            }
        }
        return false; 
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V + 1] = {0};
        for (int i = 0; i<V; i++)
        {
            if (!vis[i])
            {
                if (bfs(i, adj, vis, V)) return true; 
            }
        }
        return false; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
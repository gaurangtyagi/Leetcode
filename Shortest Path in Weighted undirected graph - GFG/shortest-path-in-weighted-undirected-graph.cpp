//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& a) {
        vector<pair<int, int>> adj[V + 1];
        for (int i = 0; i<m; i++){
            adj[a[i][0]].push_back({a[i][1], a[i][2]});
            adj[a[i][1]].push_back({a[i][0], a[i][2]});
        }
        vector<int> dis(V + 1, 1e9);
        vector<int> par(V + 1, -1);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dis[1] = 0; 
        q.push({0, 1});
        while(!q.empty())
        {
            int node = q.top().second; 
            int d = q.top().first; 
            q.pop();
            for (auto it: adj[node]){
                int weight = it.second;
                int child = it.first;
                if (d + weight < dis[child]){
                    par[child] = node;
                    dis[child] = d + weight; 
                    q.push({dis[child], child}); 
                }
            }
        }
        if (dis[V] == 1e9) return {-1};
        vector<int> path;
        int i = V; 
        while(par[i] != -1){
            path.push_back(i);
            i = par[i];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path; 
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& a) {
        // code here
        vector<pair<long long, long long>> adj[n];
        for (int i = 0; i<a.size(); i++){
            adj[a[i][0]].push_back({a[i][1], a[i][2]});
            adj[a[i][1]].push_back({a[i][0], a[i][2]});
        }
        vector<long long> dist(n, 1e11);
        vector<long long> way(n, 0);
        priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        // dist, node
        pq.push({0, 0});
        dist[0] = 0; 
        way[0] = 1; 
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long node = it.second; 
            long long step = it.first; 
            for (auto id : adj[node]){
                long long cost = id.second; 
                long long city = id.first; 
                if (cost + step < dist[city]){
                    dist[city] = cost + step; 
                    pq.push({dist[city], city});
                    way[city] = way[node]; 
                }
                else if (cost + step == dist[city]){
                    way[city] += way[node];
                }
                
            }
            
        }
        return way[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
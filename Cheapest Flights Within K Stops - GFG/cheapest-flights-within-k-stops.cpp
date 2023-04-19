//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& a, int s, int d, int K)  {
        // Code here
        vector<pair<int, int>> adj[n];
        for (int i = 0; i<a.size(); i++){
            adj[a[i][0]].push_back({a[i][1], a[i][2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q; 
        q.push({0, {s, 0}});
        dist[s] = 0; 
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first; 
            int node = it.second.first; 
            int dis = it.second.second; 
            if (stops > K) continue; 
            for (auto it : adj[node]){
                int wt = it.second; 
                int node_1 = it.first; 
                if (wt + dis < dist[node_1] && stops <= K){
                    dist[node_1] = dis + wt; 
                    q.push({stops + 1,{node_1, wt + dis}});
                }
            }
        }
        if (dist[d] == 1e9) return -1; 
        return dist[d];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
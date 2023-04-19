//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& a) {
        // Code here
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        dis[0][0] = 0; 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;
        q.push({dis[0][0],{0,0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int effort = it.first; 
            int x = it.second.first; 
            int y = it.second.second;
            for (int i = 0; i<4; i++){
                int xx = x + dr[i];
                int yy = y + dc[i];
                if (xx != -1 && yy != -1 && xx != n && yy != m){
                    int new_effort = max(effort, abs(a[x][y] - a[xx][yy]));
                    if (new_effort < dis[xx][yy]){
                        q.push({new_effort, {xx, yy}});
                        dis[xx][yy] = new_effort; 
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
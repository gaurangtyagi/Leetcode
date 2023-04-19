//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &a, pair<int, int> s, pair<int, int> d) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        queue<pair<int, pair<int, int>>> q; 
        if (s == d) return 0; 
        q.push({0,s});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis_node = it.first; 
            int x = it.second.first; 
            int y = it.second.second;
            if (it.second == d) return it.first; 
            if (x < (n-1) && dis_node + 1 < dis[x + 1][y] && a[x+1][y]){
                q.push({dis_node + 1, {x + 1, y}});
                dis[x+1][y] = dis_node + 1; 
            }
            if (y < (m-1) && dis_node + 1 < dis[x][y + 1] && a[x][y+1]){
                q.push({dis_node + 1, {x, y+1}});
                dis[x][y+1] = dis_node + 1; 
            }
            if (x && dis_node + 1 < dis[x-1][y] && a[x-1][y]){
                q.push({dis_node + 1, {x-1, y}});
                dis[x-1][y] = dis_node + 1; 
            }
            if (y && dis_node + 1 < dis[x][y-1] && a[x][y-1]){
                q.push({dis_node + 1, {x, y-1}});
                dis[x][y-1] = dis_node + 1; 
            }
        }
        return -1; 
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
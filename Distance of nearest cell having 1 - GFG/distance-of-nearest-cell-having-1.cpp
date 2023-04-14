//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>> a)
	{
	    // Code here
	    // bfs
	    int n = a.size();
	    int m = a[0].size();
	    vector<vector<bool>> vis(n, vector<bool> (m, false));
	    queue<pair<pair<int, int>, int>> q; 
	    for (int i = 0; i<n; i++)
	    {
	        for (int j = 0; j<m; j++)
	        {
	            if (a[i][j])
	            {
	                vis[i][j] = true; 
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    vector<vector<int>> ans(n, vector<int> (m, INT_MAX));
	    while(!q.empty())
	    {
	        auto it = q.front();
	        q.pop();
	        int i = it.first.first; 
	        int j = it.first.second;
	        int dis = it.second; 
	        vis[i][j] = true; 
	        ans[i][j] = min(dis, ans[i][j]); 
	        if (i && !a[i-1][j] && !vis[i-1][j])
	        {
	            q.push({{i-1, j}, dis + 1});
	        }
	        if (i < n-1 && !a[i+1][j] && !vis[i+1][j])
	        {
	            q.push({{i+1, j}, dis + 1});
	        }
	        if (j && !a[i][j - 1] && !vis[i][j - 1])
	        {
	            q.push({{i, j - 1}, dis + 1});
	        }
	        if (j < m-1 && !a[i][j + 1] && !vis[i][j + 1])
	        {
	            q.push({{i, j + 1}, dis + 1});
	        }
	    }
	    return ans; 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
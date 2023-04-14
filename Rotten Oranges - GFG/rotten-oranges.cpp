//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& a) {
        // Code here
        int n = a.size();
        int m = a[0].size();
        queue<pair<int, pair<int, int>>> q; // (time, (i, j))
        for (int i = 0; i<a.size(); i++)
        {
            for (int j = 0; j<a[0].size(); j++)
            {
                if (a[i][j] == 2)
                {
                    q.push({0, {i, j}});
                }
            }
        }
        int ans = 0; 
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it.second.first; 
            int j = it.second.second; 
            ans = it.first;
            if ((i < n - 1) && a[i + 1][j] == 1) {
                a[i+1][j]++; 
                q.push({ans + 1, {i + 1, j}});
            }
            if ((i) && a[i - 1][j] == 1) {
                a[i-1][j]++; 
                q.push({ans + 1, {i - 1, j}});
            }
            if ((j < m - 1) && a[i][j + 1] == 1) {
                a[i][j+1]++; 
                q.push({ans + 1, {i, j + 1}});
            }
            if (j && a[i][j - 1] == 1) {
                a[i][j-1]++;
                q.push({ans + 1, {i, j - 1}});
            }
        }
        for (int i = 0; i<a.size(); i++)
        {
            for (int j = 0; j<a[0].size(); j++)
            {
                if (a[i][j] == 1)
                {
                    return -1; 
                }
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
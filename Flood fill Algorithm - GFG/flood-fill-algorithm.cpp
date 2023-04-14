//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i , int j ,vector<vector<int>>&a, int newColor, int color)
    {
        if (i >= a.size() || j >= a[0].size()) return; 
        if (i < 0 || j < 0) return; 
        if (a[i][j] != color) return; 
        a[i][j] = newColor; 
        dfs(i + 1, j, a, newColor, color);
        dfs(i, j + 1, a, newColor, color);
        dfs(i - 1, j, a, newColor, color);
        dfs(i, j - 1, a, newColor, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& a, int x, int y, int newColor) {
        // Code here 
        int color = a[x][y];
        if (newColor == color) return a; 
        dfs(x, y, a, newColor, color);
        return a; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
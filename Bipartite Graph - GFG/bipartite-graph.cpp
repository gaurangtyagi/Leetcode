//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int i, vector<int> adj[], vector<int> &color)
    {
        queue<int> q; 
        q.push(i);
        color[i] = 0; 
        while(!q.empty())
        {
            int it = q.front();
            q.pop();
            for (auto ids : adj[it])
            {
                if (color[ids] == -1)
                {
                    q.push(ids); 
                    color[ids] = 1 - color[it];
                }
                else 
                {
                    if (color[ids] == color[it]) return false; 
                }
            }
        }
        return true; 
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color (V + 1, -1);
	    for (int i = 0; i<V; i++)
	    {
	        if (color[i] == -1)
	        {
	            if (!check(i, adj, color)) return false; 
	        }
	    }
	    return true; 
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
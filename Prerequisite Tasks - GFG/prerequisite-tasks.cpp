//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& a) {
	    // Code here
	    vector<int> adj[N];
	    for (int i = 0; i<a.size(); i++)
	    {
	        adj[a[i].first].push_back(a[i].second);
	    }
	    // detect cycle
	    // by toposort
	    vector<int> in(N, 0);
	    for (int i = 0; i<N; i++)
	    {
	        for (int it : adj[i])
	        {
	            in[it]++; 
	        }
	    }
	    queue<int> q; 
	    for (int i = 0; i<N; i++)
	    {
	        if (!in[i]) q.push(i);
	    }
	    int count = 0; 
	    while(!q.empty())
	    {
	       int it = q.front();
	       q.pop();
	       count++; 
	       for (auto i : adj[it])
	       {
	           if(--in[i] == 0) q.push(i);
	       }
	    }
	    return count == N; 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
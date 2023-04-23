//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int find_par(int v, vector<int> &par){
        if (v == par[v]) return v; 
        return par[v] = find_par(par[v], par);
    }
    void make_union(int a, int b, vector<int> &par, vector<int> &size){
        a = find_par(a, par);
        b = find_par(b, par);
        if (a != b){
            if (size[a] < size[b]) swap(a, b);
            par[b] = a; 
            size[b] += size[a];
        }
    }
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        vector<int> par(n, 0);
        vector<int> size(n, 1);
        int m = edges.size();
        for (int i = 0; i<n; i++){
            par[i] = i; 
        }
        int count = 0; //extra edges
        for (int i = 0; i<m; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if (find_par(a, par) == find_par(b, par)) count++; 
            else {
                make_union(a, b, par, size);
            }
        }
        int nc = 0; 
        for (int i = 0; i<n; i++){
            if (i == par[i]) nc++; 
        }
        if (nc - 1 <= count) return nc-1; 
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
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& a, int s, int e) {
        // code here
        vector<int> dist(99999, 1e9);
        queue<pair<int, int>> q; // product, steps
        q.push({s, 0});
        dist[s] = 0; 
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int step = it.second; 
            int prod = it.first; 
            if (prod == e) return step; 
            for (int i = 0; i<a.size(); i++){
                int x = (prod*a[i])%(100000);
                if (step + 1 < dist[x]){
                    q.push({x, step + 1});
                    dist[x] = step + 1; 
                }
                
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
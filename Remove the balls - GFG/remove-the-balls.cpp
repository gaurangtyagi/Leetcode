//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> a, vector<int> b) {
        stack<pair<int, int>> s; 
        for (int i = 0; i<N; i++)
        {
            if (s.empty())
            {
                s.push({a[i], b[i]});
            }
            else 
            {
                auto it = s.top();
                if (it.first == a[i] && it.second == b[i])
                {
                    s.pop();
                }
                else 
                {
                    s.push({a[i], b[i]});
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends
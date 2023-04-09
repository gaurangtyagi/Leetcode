//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here
        vector<int> dp(n , INT_MAX);
        dp[0] = 0; 
        dp[1] = abs(h[0] - h[1]);
        for (int i = 2; i<k; i++)
        {
            for (int j = i - 1; j>= 0; j--)
            {
                dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j])); 
            }
        } // base case
        for (int i = k; i<n; i++)
        {
            for (int j = 1; j<=k; j++)
            {
                dp[i] = min(dp[i], abs(h[i] - h[i - j]) + dp[i - j]);
            }
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
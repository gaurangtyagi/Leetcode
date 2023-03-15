//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size(); 
        int total = 0; 
        for (int i = 0; i<n; i++)
        {
            total += A[i];
        }
        if (total < target) return 0; 
        if ((total - target)%2) return 0; 
        int sum = (total - target)/2;
        // find number of ways to make sum 
        int dp[n + 1][sum + 1];
        dp[0][0] = 1; 
        for (int i = 1; i<= sum; i++)
        {
            dp[0][i] = 0; 
        }
        for (int i = 1; i<= n; i++)
        {
            for (int j = 0; j<= sum; j++)
            {
                if (A[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - A[i-1]];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum]; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int MCM(int i, int j, int N, int arr[])
    {
        if (i >= j) return 0; 
        int mn = INT_MAX; 
        if (dp[i][j] != -1) return dp[i][j];
        for (int k = i; k<j; k++)
        {
            int temp = MCM(i, k, N, arr) + MCM(k + 1, j, N, arr) + arr[i-1]*arr[k]*arr[j];
            if (temp < mn)
            {
                mn = temp; 
            }
        }
        return dp[i][j] = mn; 
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return MCM(1, N-1, N, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
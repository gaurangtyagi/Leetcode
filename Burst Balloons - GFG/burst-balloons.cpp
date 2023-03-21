//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
int dp[303][303]; 
    int MCM(int i, int j, int n, vector<int>& arr)
    {
        if (i >= j) return 0; 
        if (dp[i][j] != -1) return dp[i][j];
        int mn = INT_MIN; 
        for (int k = i; k<j; k++)
        {
            int temp = MCM(i, k, n, arr) + MCM(k + 1, j, n, arr);
            temp += arr[i - 1]*arr[k]*arr[j];
            if (mn < temp)
            {
                mn = temp; 
            }
        }
        return dp[i][j] = mn; 
    }
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        memset(dp, -1, sizeof(dp));
        return MCM(1, arr.size() - 1, arr.size(), arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
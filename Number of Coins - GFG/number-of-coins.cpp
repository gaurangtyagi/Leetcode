//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int n = M;
        int64_t dp[n + 1][V + 1];
        memset(dp , -1, sizeof(dp));
        for (int j = 0; j<= V; j++)
        {
            dp[0][j] = INT_MAX;
        }
        for (int i = 0; i<= n; i++)
        {
            dp[i][0] = 0; 
        }
        for (int i = 1; i<= n; i++)
        {
            for (int j = 1; j<= V; j++)
            {
                if (coins[i-1] <= j)
                {
                    dp[i][j] = min(dp[i-1][j], dp[i][j - coins[i-1]] + 1);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][V] != INT_MAX)
           return  dp[n][V];
        return -1; 
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
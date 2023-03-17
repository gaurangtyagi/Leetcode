//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int LCS(string text1, string text2) {
            int n = text1.size();
            int m = text2.size();
            int dp[n + 1][m + 1]; 
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i<= n; i++)
            {
                for (int j = 1; j<= m; j++)
                {
                    if (text1[i-1] == text2[j-1])
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else 
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            return dp[n][m];    
        }
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    // Your code goes here
	    return (X.size() - LCS(X, Y))*costX + (Y.size() - LCS(X, Y))*costY;
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
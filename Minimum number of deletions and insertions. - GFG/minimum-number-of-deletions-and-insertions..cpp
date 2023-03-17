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
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    return (str1.size() + str2.size() - LCS(str1, str2)*2);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
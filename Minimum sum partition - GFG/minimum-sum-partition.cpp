//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0; 
	    for (int i = 0; i<n; i++)
	    {
	        sum += arr[i];
	    }
	     
	    // s1 + s2 = sum
	    // s2 = sum - s1; 
	    // min --> abs(s1 - s2)
	    // min --> abs(sum - 2*s1)
	    // s1 = sum/2; 
	    // find value nearest to this
	    
	    bool dp[n + 1][sum + 1];
	    for (int i = 0; i<= n; i++)
	    {
	        dp[i][0] = true; 
	    }
	    for (int i = 1; i<= sum; i++)
	    {
	        dp[0][i] = false; 
	    }
	    int minimum = INT_MAX; 
	    for (int i = 1; i<= n; i++)
	    {
	        for (int j = 1; j<= sum; j++)
	        {
	            if (arr[i-1] <= j)
	            {
	                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
	            }
	            else 
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	            if (dp[i][j]) minimum = min(minimum, abs(sum - 2*j));
	        }
	    }
	    return minimum; 
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
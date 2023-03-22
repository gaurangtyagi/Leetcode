//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int dp[10004][101];
    // floor
    // number of eggs
    // brute force need to be optimized by binary search 
    int64_t eggdrop(int floor, int egg)
    {
        if (egg <= 1 || floor == 1 || floor == 0) return floor; // base case
        if (dp[floor][egg] != -1) return dp[floor][egg];
        int64_t ans = INT_MAX;
        // this o(n) loop can be reduced to o(logn) 
        // for (int k = 1; k<= floor; k++)
        // {
        //     int64_t temp = 1 + max(eggdrop(k - 1,egg-1), eggdrop(floor - k, egg));
        //     ans = min(ans, temp);
        // }
        int low = 1; 
        int high = floor;
        while(low <= high)
        {
            int64_t mid = (low + high)/2;
            int64_t does_break = eggdrop(mid - 1, egg - 1);
            int64_t not_break = eggdrop(floor  - mid, egg);
            int64_t temp = 1 + max(does_break, not_break);
            ans = min(ans, temp);
            if (not_break < does_break)
            {
                high = mid-1; 
            }
            else 
            {
                low = mid + 1; 
            }
        }
        return dp[floor][egg] = ans; 
    }
    int eggDrop(int k, int n) 
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return eggdrop(n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
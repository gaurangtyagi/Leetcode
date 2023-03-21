//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool is_palin(string& s, int i , int j)
    {
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    int MCM(int i, int n, string& s, vector<int> & dp)
    {
        if (i == n) return 0; 
        if (dp[i] != -1) return dp[i];
        if (is_palin(s, i, n)) return 0; // no further partition is required
        int ans = INT_MAX;
        for (int k = i; k<n; k++)
        {
            if (is_palin(s, i, k))
            {
                int temp = MCM(k + 1, n, s, dp) + 1;
                ans = min(ans, temp);
            }
        } 
        return dp[i] = ans; 
    }
    int palindromicPartition(string s)
    {
        // code here
        int n = s.length();
        vector<int> dp(n + 1, - 1);
        return MCM(0, n-1, s, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[202][202][2];
    int solve(int i, int j , string S, int N, bool is_true)
    {
        if (i > j) return 0; 
        if(dp[i][j][is_true] != -1) return dp[i][j][is_true];
        if (i == j)
        {
            if (is_true == true)
             return S[i] == 'T';
            else 
             return S[i] == 'F';
        }
        int ans = 0; 
        for (int k = i + 1; k < j; k+= 2)
        {
            int LT = solve(i, k-1, S, N, true);
            int LF = solve(i, k-1, S, N, false);
            int RT = solve(k+1, j, S, N, true);
            int RF = solve(k+1, j, S, N, false);
            
            if (S[k] == '&')
            {
                if (is_true)
                {
                    ans += LT * RT; 
                }
                else 
                {
                    ans += LT * RF + RT*LF + LF*RF;
                }
            }
            else if (S[k] == '|')
            {
                if (is_true)
                {
                    ans += LT*RT + LT*RF + RT*LF; 
                }
                else 
                {
                    ans += LF*RF; 
                }
            }
            else if (S[k] == '^')
            {
                if (is_true)
                {
                    ans += LT*RF + RT*LF; 
                }
                else 
                {
                    ans += LT*RT + LF*RF; 
                }
            }
        }
        return dp[i][j][is_true] = (ans)%1003; 
    }
    int countWays(int N, string S){
        // code here
        // MCM
        memset(dp , -1, sizeof(dp));
        return solve(0, N-1, S, N, true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
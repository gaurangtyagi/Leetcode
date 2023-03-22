//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string, bool> dp;
    bool isScramble(string s, string t){
        //code here
        if (dp.find(s + t) != dp.end()) return dp[s + t];
        if (s == t) return true; 
        int ans = INT_MAX; 
        int n = s.length();
        for (int i = 1; i< n; i++)
        {
            bool cond1 = isScramble(s.substr(0, i), t.substr(0, i)) && isScramble(s.substr(i, n- i), t.substr(i, n-i));
            bool cond2 = isScramble(s.substr(0, i), t.substr(n-i, i)) && isScramble(t.substr(0, n-i), s.substr(i,n- i));
            // cond1 == swapping is performed
            // cond2 == swapping is not performed
            if (cond1 || cond2)
            {
                dp[s + t] = true; 
                return true; 
            }
        }
        dp[s + t] = false; 
        return false; 
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
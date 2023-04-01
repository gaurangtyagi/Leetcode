//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool helper(int mid, int n, int k , vector<int> a)
    {
        int last = 0;
        int i = 0; 
        k--; 
        while(i < n)
        {
            if (abs(a[i] - a[last]) >= mid)
            {
                k--; 
                last = i; 
                i++; 
            }
            else 
            {
                i++; 
            }
            if (k == 0) return true; 
        }
        if (k == 0) return true; 
        else return false; 
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int low = 1; 
        int high = 1e9 + 7; 
        int ans = -1; 
        sort(stalls.begin(), stalls.end());
        while(low <= high)
        {
            int mid = (low + high)/2;
            if (helper(mid, n, k, stalls))
            {
                ans = mid; 
                low = mid + 1; 
            }
            else 
            {
                high = mid - 1; 
            }
        }
        //cout<<helper(2, n, k, stalls);
        return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
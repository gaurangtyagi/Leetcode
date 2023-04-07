//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string s){    
        //code here
        string t = s; 
        reverse(t.begin(), t.end());
        int ans = 0; 
        while(s != t)
        {
            ans++; 
            s.pop_back();
            t.erase(t.begin());
        }
        return ans; 
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
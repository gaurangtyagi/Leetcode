//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int x,int y,string S){
      //code here
      string X = "pr";
      string Y = "rp";
      if (x < y)
      {
          swap(x, y);
          swap(X, Y);
      }
      // x is big then why
      stack<char> s; 
      long long ans = 0; 
      for (int i = 0; i<S.length(); i++)
      {
          if (s.empty())
          {
              s.push(S[i]);
          }
          else 
          {
              string temp = "";
              temp += s.top();
              temp += S[i];
              if (temp == X)
              {
                  ans += x;
                  s.pop();
              }
              else 
              {
                  s.push(S[i]);
              }
          }
      }
      string p = "";
      while(!s.empty())
      {
          p += s.top();
          s.pop();
      }
      reverse(p.begin(), p.end());
      for (int i = 0; i<p.length(); i++)
      {
          if (s.empty())
          {
              s.push(p[i]);
          }
          else 
          {
              string temp = "";
              temp += s.top();
              temp += p[i];
              if (temp == Y)
              {
                  ans += y;
                  s.pop();
              }
              else 
              {
                  s.push(p[i]);
              }
          }
      }
      return ans; 
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
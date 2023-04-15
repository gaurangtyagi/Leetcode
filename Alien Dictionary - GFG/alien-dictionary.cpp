//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> gr[K]; 
        for (int i = 0; i<N - 1; i++)
        {
            string s = dict[i];
            string t = dict[i + 1];
            for (int j = 0; j<min(s.length(), t.length()); j++)
            {
                if (s[j] != t[j])
                {
                    gr[s[j] - 'a'].push_back(t[j] - 'a');
                    break; 
                }
            }
        }
        string topo = "";
        vector<int> in(K, 0);
        queue<int> q; 
        for (int i = 0; i<K; i++)
        {
            for (int j : gr[i])
            {
                in[j]++; 
            }
        }
        for (int i = 0; i<K; i++)
        {
            if (!in[i]) q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo += ('a' + node);
            for (int it: gr[node])
            {
                if (--in[it] == 0) q.push(it);
            }
        }
        return topo; 
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
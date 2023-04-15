//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& wordList) {
        // Code here
        unordered_map<string, bool> mp; 
        for (int i = 0; i<wordList.size(); i++)
        {
            mp[wordList[i]] = true; 
        }
        queue<pair<string, int>> q; 
        q.push({s, 1});
        if (mp[s]) mp[s] = false; 
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            string temp = it.first; 
            int step = it.second; 
            if (temp == t) return step; 
            for (int i = 0; i<temp.size(); i++)
            {
                char original = temp[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    temp[i] = ch; 
                    if (mp[temp]){
                        mp[temp] = false; 
                        q.push({temp, step + 1});
                    }
                }
                temp[i] = original; 
            }
        }
        return 0; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
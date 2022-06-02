class Solution {
public:
       vector<vector<int>> transpose(vector<vector<int>> A) {
        int M = A.size();
        int N = A[0].size();
        vector<vector<int>> ans(N, vector<int>(M, 0));
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
                ans[j][i] = A[i][j];
        return ans;
    }
};
class Solution {
public:
    int initial_color; 
    void dfs(int i , int j, vector<vector<int>>& image, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        if (i < 0 || j < 0) return; 
        if ( i>= n || j >= m ) return ; 
        if (initial_color != image[i][j]) return; 
        image[i][j] = newColor;
        dfs(i , j - 1, image, newColor);
        dfs(i, j + 1, image, newColor);
        dfs(i - 1, j,image,  newColor);
        dfs(i + 1, j, image, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        initial_color = image[sr][sc];
        if (initial_color != newColor)dfs(sr, sc, image, newColor);
        return image; 
    }
};
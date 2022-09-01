/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(int& ans, TreeNode* root, int max_sum)
    {
        if (root->val >= max_sum)
        {
            max_sum = root->val; 
            ans++;
        }
        if (root->left) dfs(ans, root->left, max_sum);
        if (root->right) dfs(ans, root->right, max_sum);
    }
    int goodNodes(TreeNode* root) 
    {
        int ans = 0; 
        dfs(ans, root, INT_MIN);
        return ans;         
    }
};
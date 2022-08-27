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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if (root == NULL) return 0; 
        int ans = 0; 
        queue<pair<TreeNode*,int64_t>> q; 
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level; 
            int minn = q.front().second;
            for (int i = 0; i<size; i++)
            {
                auto temp = q.front();
                level.push_back(temp.second-minn);
                q.pop();
                if (temp.first->left) q.push({temp.first->left, 2*(temp.second-minn) + 1});
                if (temp.first->right) q.push({temp.first->right, 2*(temp.second-minn) + 2});
            }
            ans = max(ans , level[size-1] - level[0] + 1);
        }
        return ans;
    }
    
};
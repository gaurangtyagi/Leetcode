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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q; 
        vector<vector<int>> ans; 
        map<int, map<int, multiset<int>>> ds; 
        if (!root) return ans; 
        q.push({root,{0, 0}}); 
        while(!q.empty())
        {
          auto it = q.front();
            q.pop();
            TreeNode *node = it.first; 
            int row = it.second.first; 
            int col = it.second.second; 
            ds[row][col].insert(node->val);
            if (node->left) 
                q.push({node->left, {row - 1, col -1}});
            if (node->right)
                q.push({node->right, {row + 1, col - 1}});
        }
        for (auto it : ds)
        {
            vector<int> res; 
            for (auto itr : it.second)
            {
                res.insert(res.begin(), itr.second.begin(), itr.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};
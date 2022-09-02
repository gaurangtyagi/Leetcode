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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans; 
        queue<TreeNode*> q; 
        if (!root) return ans;
        q.push(root); 
        while(!q.empty())
        {
            int size = q.size();
            double store = 0.0; 
            for (int i = 0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                store += node->val;
            }
            store /= size;
            ans.push_back(store);
        }
        return ans;
        
    }
};
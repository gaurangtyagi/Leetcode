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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            map<int, int> mp; 
            for (int i = 0; i<n; i++)
            {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (node->left && node->right)
                {
                    if ((node->left->val == x && node->right->val == y)|| (node->left->val == y && node->right->val == x)) return false; 
                }
                mp[node->val]++;
            }
            if (mp.find(x) != mp.end() && mp.find(y) != mp.end()) return true; 
            else mp.clear();
        }
        return false; 
    }
};
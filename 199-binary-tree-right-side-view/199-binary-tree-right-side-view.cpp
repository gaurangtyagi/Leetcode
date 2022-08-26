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
    void traversal(vector<int> &res, int level, TreeNode* node)
    {
        if (node == NULL) return; 
        if (res.size() == level) res.push_back(node->val);
        traversal(res, level + 1, node->right);
        traversal(res, level + 1, node->left);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        traversal(res, 0, root);
        return res; 
    }
};
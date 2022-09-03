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
    void preorder(TreeNode* root, map<int, int>& mp)
    {
        if(root == NULL) return; 
        mp[root->val]++;
        preorder(root->left, mp);
        preorder(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> ans; 
        map<int, int> mp;
        preorder(root, mp);
        int curr_max = 0; 
        for (auto it: mp)
        {
            if (it.second > curr_max) curr_max = it.second; 
        }
        for (auto it: mp)
        {
            if (it.second == curr_max) ans.push_back(it.first);
        }
        return ans;
    }
};
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
    // void preorder(TreeNode* root)
    // {
    //     if (root == NULL) return;
    //     v.push_back(root->val);
    //     preorder(root->left);
    //     preorder(root->right);
    // } recursive
    
    vector<int> preorderTraversal(TreeNode* root) //iterative
    {
        vector<int> ans;
        stack<TreeNode*> st; 
        if (!root) return ans; 
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            ans.push_back(node->val);
        }
        return ans;
    }
};
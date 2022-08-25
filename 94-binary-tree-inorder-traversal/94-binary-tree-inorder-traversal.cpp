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
    // void inorder(TreeNode* root)
    // {
    //     if (root == NULL) return;
    //     inorder(root->left);
    //     v.push_back(root->val);
    //     inorder(root->right);
    // } recursive
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> pre; 
        vector<int> in; 
        vector<int> post;
        if (root == NULL) return in; 
        stack<pair<TreeNode*, int>> st; 
        st.push({root, 1});
        
        while(!st.empty())
        {
            auto it = st.top(); 
            st.pop();
            if (it.second == 1)
            {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->left) st.push({it.first->left, 1});
            }
            else if (it.second == 2)
            {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->right) st.push({it.first->right, 1});
            }
            else if (it.second == 3)
            {
                post.push_back(it.first->val);
            }
        } 
        return in;
        // vector<int> ans; 
        // stack<TreeNode*> s;
        // TreeNode* node = root;
        // while(true)
        // {
        //     if (node)
        //     {
        //         s.push(node);
        //         node = node->left;
        //     }
        //     else 
        //     {
        //         if (s.empty()) break;
        //         node = s.top();
        //         s.pop();
        //         ans.push_back(node->val);
        //         node = node->right;
        //     }
        // } iterative
        //return ans;
    }
};
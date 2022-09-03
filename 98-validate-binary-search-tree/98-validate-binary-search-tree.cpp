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
    bool fail = 0;
    void inorder(TreeNode* root, TreeNode*&prev)
    {
        if (root == NULL) return; 
        inorder(root->left, prev);
        if (prev != NULL && root->val <= prev->val)
        {
            fail = 1; 
        }
        prev = root; 
        inorder(root->right, prev);
    }
    bool isValidBST(TreeNode* root) 
    {
        TreeNode* prev = NULL; 
        inorder(root, prev);
        return !fail; 
    }
};
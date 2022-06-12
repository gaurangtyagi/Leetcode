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
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector <int> v;
        if (root == NULL)
        {
            return ans;
        }
        else
        {
            while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                ans.push_back(v);
                while(!v.empty()) v.pop_back();
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                v.push_back(temp->val);
                if (temp -> left)
                {
                    q.push(temp -> left);
                }
                if (temp -> right)
                {
                    q.push(temp -> right);
                }
            }
            
        }
        return ans;
        }
        
    }
};
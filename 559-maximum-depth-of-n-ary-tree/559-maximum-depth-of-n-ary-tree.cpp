/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) 
    {
        if (root == NULL) return 0; 
        vector<int> v; 
        int maximum = 0;
        for (auto child : root->children)
        {
            int depth = maxDepth(child);
            v.push_back(depth);
        }
        for (int i = 0; i<v.size(); i++) maximum = max(maximum, v[i]);
        return (1 + maximum);
    }
};
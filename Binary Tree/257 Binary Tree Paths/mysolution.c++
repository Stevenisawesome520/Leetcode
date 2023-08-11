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

    string temp;
    vector<string> ans;
    void traverse(TreeNode* root)
    {
        if(!(root->left) && !(root->right))
        {
            if(temp.empty())
                ans.push_back(to_string(root->val));
            else
                ans.push_back(temp + "->" + to_string(root->val));
            return;
        }
        string node = temp.empty() ? to_string(root->val) :  "->" + to_string(root->val);
        temp = temp+node;

        
        if(root->left) traverse(root->left);
        if(root->right) traverse(root->right);
        temp = temp.substr(0,temp.size()-node.size());
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root);
        return ans;
    }
};

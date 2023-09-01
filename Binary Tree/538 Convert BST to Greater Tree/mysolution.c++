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
    int right = 0;
    void makeGT(TreeNode* root)
    {
        if(!root) return;
        makeGT(root->right);
        root->val += right;
        right = root->val;
        makeGT(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        makeGT(root);
        return root;
    }
};

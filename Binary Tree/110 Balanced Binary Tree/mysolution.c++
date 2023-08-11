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
    bool ans = true;
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if(abs(leftHeight - rightHeight) > 1)
            ans = false;

        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return ans;
    }
};

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
    int ans = 0;
    int count = 0;
    int getHeight(TreeNode *root)
    {
        if(!root)
            return 0;
        
        int leftH = getHeight(root->left);
        int rightG = getHeight(root->right);
        if(leftH == 1)
            ans += root->left->val;
        
        return max(leftH, rightG) +1 ;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        getHeight(root);
        return ans;
    }
};

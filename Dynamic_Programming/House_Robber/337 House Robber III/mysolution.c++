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

    int take = 0;
    int nonTake = 0;
    int ans = 0;
    void traverse(TreeNode* root)
    {

        if(!root)
        {
            take = 0;
            nonTake = 0;
            return;
        } 
        traverse(root->left);
        int left_take = take;
        int left_nonTake = nonTake;
        traverse(root->right);
        int right_take = take;
        int right_nonTake = nonTake;

        take = root->val + left_nonTake + right_nonTake;
        nonTake = max({left_take + right_take, left_nonTake + right_nonTake, left_take + right_nonTake, right_take + left_nonTake});

        ans = max({ans, take, nonTake});

    }
    int rob(TreeNode* root) {
        traverse(root);
        return ans;
    }
};

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
    bool ans = false;

    void traversal(TreeNode* root, int target)
    {
        if(root->left==nullptr && root->right==nullptr)
        {
            if(target - root->val==0)
                ans = true;

            return;
        }
        if(!ans && root->left) traversal(root->left, target-root->val);
        if(!ans && root->right) traversal(root->right, target-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        traversal(root, targetSum);

        return ans;
    }
};

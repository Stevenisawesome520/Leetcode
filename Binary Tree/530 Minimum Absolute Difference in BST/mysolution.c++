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
    int mimD = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return INT_MAX;
        int num1 = getMinimumDifference(root->left);
        if(pre) num1 = min(num1, abs(root->val-pre->val));
        pre = root;

        int num2 = getMinimumDifference(root->right);

        return min(num2, num1);


    }
};

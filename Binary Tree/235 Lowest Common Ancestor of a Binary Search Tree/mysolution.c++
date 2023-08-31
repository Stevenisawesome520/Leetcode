/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;

        TreeNode *right = nullptr;
        TreeNode *left = nullptr;
        if(p->val < root->val && q->val < root->val)
            left = lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            right = lowestCommonAncestor(root->right, p, q);
        else
        {
            left = lowestCommonAncestor(root->left, p, q);
            right = lowestCommonAncestor(root->right, p, q);
        }

        if(left && right)   return root;
        if(!left)   return right;
        return left;
                        
    }
};

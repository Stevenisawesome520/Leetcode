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
    bool left = false, right = false;
    TreeNode *ans = nullptr;
    void traverse(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return;

        if(!ans) traverse(root->left, p, q);

        bool tempL = left, tempR = right;
        left=false;
        right=false;
        if(!ans) traverse(root->right, p, q);
        
        if(tempL) left = true;
        if(tempR) right = true;

        if(root == p) left = true;
        else if(root == q) right = true;

        if(left && right && !ans )
            ans = root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return ans;
    }
};

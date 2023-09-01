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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)   return root;
        if(low == high && root->val < low)
            return trimBST(root->right, low, high);
        else if(low == high && root->val > low)
            return trimBST(root->left, low, high);
        else if(low == high && root->val == low)
        {
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        else if(root->val < low)
        {
            root = root->right;
            while(root && root->val < low)
                root = root->right;
                
            if(root && root->val > high)    root = root->left;
            while(root && root->val > high)
                root = root->left;

            if(root) root->left = trimBST(root->left, low, high);
            if(root) root->right = trimBST(root->right, low, high);
            return root;
        }
        else if(root->val > high)
        {
            root = root->left;
            while(root && root->val > high)
                root = root->left;

            if(root && root->val < low)    root = root->right;
            while(root && root->val < low )
                root = root->right;

            if(root) root->left = trimBST(root->left, low, high);
            if(root) root->right = trimBST(root->right, low, high);
            return root;
        }
        else
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }


        return root;
    }
};

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

//recursive
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        if(root->val > val && root->left) insertIntoBST(root->left, val);
        else if(root->val < val && root->right) insertIntoBST(root->right, val);
        else if(root->val > val) root->left = new TreeNode(val);
        else if(root->val < val) root->right = new TreeNode(val);

        return root;
    }
};

//iterative

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode *ans = root;
        while(root->val != val)
        {
            if(root->val < val && root->right)
                root = root->right;
            else if(root->val > val && root->left)
                root = root->left;
            else if(root->val < val)
            {
                root->right = new TreeNode(val);
                root=root->right;
            }
            else
            {
                root->left = new TreeNode(val);
                root=root->left;
            }
        }

        return ans;
    }
};

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        else if(val == root->val) return root;
        else if(val > root->val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }
};

//iterative
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && val!= root->val)
        {
            if(root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};

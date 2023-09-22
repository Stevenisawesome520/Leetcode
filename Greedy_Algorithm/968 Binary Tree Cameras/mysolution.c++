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

    //cam = 2;
    //light = 1;
    int ans = 0;
    void traversal(TreeNode* root)
    {
        if(!root) return;
        traversal(root->left);
        traversal(root->right);


        if(root->left && !root->right && root->val == 0)
        {
            if(root->left->val == 2)
                root->val = 1;
            else if(root->left->val == 0)
            {
                root->val = 2; 
                ans++;
            }
                
        }
        else if(!root->left && root->right && root->val == 0)
        {
            if(root->right->val == 2)
                root->val = 1;
            else if(root->right->val == 0)
            {
                root->val = 2; 
                ans++;
            }
        }
        else if(root->left && root->right && root->val == 0)
        {
           
            if(root->right->val == 2 || root->left->val == 2)
                root->val = 1;
            if(root->right->val == 0 || root->left->val == 0)
            {
                
                root->val = 2; 
                ans++;
            }
        }
    } 
    int minCameraCover(TreeNode* root) {
        traversal(root);

        if(root->val == 0)
            ans++;

        return ans;
    }
};

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key)
        {
            TreeNode* left = root->left;
            TreeNode* temp = root->right;
            if(temp)
            {
                while(temp->left)
                    temp = temp->left;
                

                temp->left = left;
                return root->right;
            }
            else
            {
                return left;
            }
                
        }
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else 
            root->right = deleteNode(root->right, key);

        return root;

    }
};

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
    int maxD = 0;
    int curD = 0;
    int count = 0;
    bool pass = false;
    void traverse(TreeNode* node)
    {
        if(pass) return;
        curD++;
        if(node->left == nullptr && node->right == nullptr && curD == maxD)
        {
            count++;
            curD--;
            return;
        }
        else if(node->left == nullptr && node->right == nullptr && curD != maxD)
        {
            pass = true;
            return;
        }
        else if(node->right == nullptr)
        {
            count++;
            pass = true;
            return;
        }
        
        traverse(node->left);
        traverse(node->right);
        curD--;
    
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        TreeNode* temp = root;
        while(temp != nullptr)
        {
            maxD++;
            temp = temp->left;
        }
        traverse(root);
        return pow(2, maxD-1) - 1 + count;
    }
};

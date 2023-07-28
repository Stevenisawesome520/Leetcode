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
    void traverse(TreeNode* n)
    {
        curD++; 
        if(n == nullptr)
        {
            maxD = max(maxD, --curD);
            return;
        }

        traverse(n->left);
        traverse(n->right);
        curD--;
    }
    int maxDepth(TreeNode* root) {
        traverse(root);
        return maxD;
    }
};

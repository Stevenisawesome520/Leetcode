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
    int minD = INT_MAX;
    int curD = 0;
    void traverse(TreeNode* n)
    {
        curD++; 
        if(n == nullptr)
        {
            //minD = min(minD, --curD);
            --curD;
            return;
        }
        else if(n->left == nullptr && n->right == nullptr)
        {
            minD = min(minD, curD);
            curD--;
            return;
        }
        traverse(n->left);
        traverse(n->right);
        curD--;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        traverse(root);
        return minD;
    }
};

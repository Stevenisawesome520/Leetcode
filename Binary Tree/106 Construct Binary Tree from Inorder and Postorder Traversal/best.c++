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
    unordered_map<int, int> tab;
    TreeNode* Tree(vector<int>& inorder, int x, int y, vector<int>& postorder, int a, int b)
    {
        if(x > y || a > b) return nullptr;
        TreeNode* node = new TreeNode(postorder[b]);
        int idx = tab[postorder[b]];
        node->left = Tree(inorder, x, idx-1, postorder, a, a+idx-x-1);
        node->right = Tree(inorder, idx+1, y, postorder, a+idx-x, b-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        for(int i = 0; i < len; i++)
            tab[inorder[i]] = i;

        return Tree(inorder, 0, len-1, postorder, 0, len-1);
    }
};

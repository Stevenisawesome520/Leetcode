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
    TreeNode* Traversal(vector<int>& nums, int left, int right)
    {   
        if(left > right)    return nullptr;
        TreeNode* root = new TreeNode(nums[(right - left)/2 + left]);
        root->left = Traversal(nums, left, (right - left)/2 + left - 1);
        root->right = Traversal(nums, (right - left)/2 + left + 1, right);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return  Traversal(nums, 0, nums.size()-1);
    }
};

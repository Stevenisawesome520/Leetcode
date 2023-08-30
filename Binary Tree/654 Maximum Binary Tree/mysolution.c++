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
    TreeNode* Tree(vector<int>& nums, int left, int pivot, int right)
    {
        if(pivot > right || pivot < left) return nullptr;
        TreeNode* node = new TreeNode(nums[pivot]);

        int max = left;
        for(int i = left+1; i < pivot; i++)
        {
            if(nums[i] > nums[max])
                max = i;
        }
        node->left = Tree(nums,left, max, pivot-1);

        max = pivot+1;
        for(int i = max+1; i <= right; i++)
        {
            if(nums[i] > nums[max])
                max = i;
        }
        node->right = Tree(nums, pivot+1, max, right);

        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int max = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[max])
                max = i;
        }
        return Tree(nums,0,max,nums.size()-1);
    }
};

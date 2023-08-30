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
    stack<int> st;
    bool ans = true;
    void traverse(TreeNode* root)
    {
        if(root && ans)
        {
            traverse(root->left);
            if(!st.size())
                st.push(root->val);
            else
            {
                if(root->val > st.top())
                {
                    st.pop();
                    st.push(root->val);
                }
                else
                    ans = false;
            }
            traverse(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        traverse(root);
        return ans;
    }
};

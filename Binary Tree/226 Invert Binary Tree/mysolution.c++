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


//Recursive
class Solution {
public:
    void swapNode(TreeNode *head)
    {
        if(head == nullptr) return;
        TreeNode *temp = head->right;
        head->right = head->left;
        head->left = temp;
        swapNode(head->left);
        swapNode(head->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        swapNode(root);
        return root;
    }
};

//Non-Recursive
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *t = st.top();
            swap(t->left, t->right);
            st.pop();
            if(t->left) st.push(t->left);
            if(t->right) st.push(t->right);
        }
        return root;
    }
};

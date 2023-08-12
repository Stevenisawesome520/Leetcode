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

//BFS Iterative
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = root->val;
        while(!q.empty())
        {
            int size = q.size();
            ans = q.front()->val;
            for(int i = 0; i < size; i++)
            {
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);             
                q.pop();      
            }
        }
        return ans;
    }
};


//Recursive
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
    int maxDeep = 1;
    int ans;
    void traversal(TreeNode* root, int deep = 1)
    { 
        if(!root->left && !root->right)
        {
            if(deep > maxDeep)
                ans = root->val;
            maxDeep = max(maxDeep, deep);
            return;
        }
        maxDeep = max(maxDeep, deep);
        if(root->left) traversal(root->left, deep+1);
        if(root->right) traversal(root->right, deep+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        ans = root->val;
        traversal(root);
        return ans;
    }
};

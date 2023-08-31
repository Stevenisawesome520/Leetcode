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
    int maxC= -1;
    int count = 0;
    TreeNode * pre = nullptr;
    vector<int> ans;
    void traverse(TreeNode* root)
    {
        if(!root) return;

        traverse(root->left);
        if(pre && pre->val == root->val)
        {
            count++;
        }
        else if(pre && pre->val != root->val)
        {
            if(count > maxC)
            {
                vector<int>().swap(ans);
                ans.push_back(pre->val);
                maxC = count;
            }
            else if(count == maxC)
            {
                ans.push_back(pre->val);
            }
            count = 0;
        }
        pre = root;
        traverse(root->right);
        
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        if(count > maxC)
        {
            vector<int>().swap(ans);
            ans.push_back(pre->val);
            maxC = count;
        }
        else if(count == maxC)
        {
            ans.push_back(pre->val);
        }

        return ans;
    }
};

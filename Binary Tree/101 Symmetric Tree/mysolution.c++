
//Recursive
class Solution {
public:

    bool compare(TreeNode* l, TreeNode* r)
    {
        bool leftBool = true;
        bool rightBool = true;

        if(l->val != r->val) return false;
        if(l->left != nullptr && r->right != nullptr)
            leftBool = compare(l->left, r->right);
        else if(l->left != nullptr || r->right != nullptr)
            return false;
        else
            leftBool = true;

        if(l->right != nullptr && r->left != nullptr)
            rightBool = compare(l->right, r->left);
        else if(l->right != nullptr || r->left != nullptr)
            return false;
        else
            rightBool = true;

        return leftBool && rightBool;

        
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        else if(root->left == nullptr || root->right == nullptr)
            return false;
        return compare(root->left, root->right);
    }
};


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

//Non-recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        else if(root->left == nullptr || root->right == nullptr)
            return false;

        queue<TreeNode* > leftV, rightV;
        leftV.push(root->left);
        rightV.push(root->right);
        while(!leftV.empty() && !rightV.empty())
        { 
            int l = leftV.size();
            for(int i = 0; i < l; i++)
            {
                if((leftV.front() == nullptr) && (rightV.front() == nullptr))
                {
                    leftV.pop();
                    rightV.pop();
                    continue;
                }
                if((leftV.front() == nullptr) || (rightV.front() == nullptr))
                    return false;
                if(leftV.front()->val != rightV.front()->val)
                    return false;

                leftV.push(leftV.front()->left);
                leftV.push(leftV.front()->right);
                leftV.pop();
                rightV.push(rightV.front()->right);
                rightV.push(rightV.front()->left);
                rightV.pop();
            }
        }
        return true;
    }
};

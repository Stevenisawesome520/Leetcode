class Solution {
public:
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {0, 0};
        auto [leftDontRob, leftRob]   = dfs(root -> left);
        auto [rightDontRob, rightRob] = dfs(root -> right);
        return {
            max(leftDontRob, leftRob) + max(rightDontRob, rightRob),
            root -> val + leftDontRob + rightDontRob
        };
    }
};

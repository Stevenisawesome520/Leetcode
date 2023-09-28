class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<vector<int>> dp(len2 + 1, vector<int>(len1 + 1, 0));
        for(int i = 1; i <= len2; i++)
        {
            for(int j = 1; j <= len1; j++)
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(nums2[i-1] == nums1[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);

            }
        }
        return dp[len2][len1];
    }
};

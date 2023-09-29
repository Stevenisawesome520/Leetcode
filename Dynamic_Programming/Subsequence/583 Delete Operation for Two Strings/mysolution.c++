class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len2 + 1, vector<int>(len1 + 1, 1001));

        dp[0][0] = 0;
        for(int i = 1; i <= len1; i++)
            dp[0][i] = i;
        for(int i = 1; i <= len2; i++)
            dp[i][0] = i;

        for(int i = 1; i <= len2; i++)
        {
            for(int j = 1; j <= len1; j++)
            {
                dp[i][j] = word1[j-1] == word2[i-1] ? dp[i-1][j-1] : min(dp[i-1][j], dp[i][j-1]) + 1;

            }

        } 
    
        return dp[len2][len1];
    }
};

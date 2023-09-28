class Solution {
public:
    int numDistinct(string s, string t) {
        //return 0;
        int len1 = s.size(), len2 = t.size();
        vector<vector<int>> dp(len2 + 1, vector<int>(len1 + 1, 0));
        for(int i = 0; i <= len1; i++)
            dp[0][i] = 1;
        for(int i = 1; i <= len2; i++)
        {
            for(int j = 1; j <= len1; j++)
            {
                if(t[i-1] == s[j-1])
                {
                    if(dp[i-1][j-1]  < INT_MAX - dp[i][j-1])
                        dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else
                    dp[i][j] =  dp[i][j-1];
            }
        }

        return dp[len2][len1];
    }
};

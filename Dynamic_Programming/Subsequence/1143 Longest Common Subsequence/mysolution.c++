class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<int> dp(len1, 0);
        if(text1[0] == text2[0])
            dp[0] = 1;
        for(int i = 1; i < len1; i++)
        {   
            if(dp[i-1] || text1[i] == text2[0])
                dp[i] = 1;
        }

        for(int i = 1; i < len2; i++)
        {
            for(int j = len1-1; j >= 0; j--)
            {
                if(j==0 && text1[j] == text2[i])
                {
                    dp[0] = 1;
                }
                else if(j != 0)
                {
                    if(text1[j] == text2[i])
                        dp[j] = max(dp[j], dp[j-1] + 1);
                    else
                        dp[j] = max(dp[j], dp[j-1]);
                }

            }
            for(int j = 1; j < len1; j++)
                if(dp[j] < dp[j-1])
                    dp[j] = dp[j-1];

        }
        return dp[len1-1];
    }
};

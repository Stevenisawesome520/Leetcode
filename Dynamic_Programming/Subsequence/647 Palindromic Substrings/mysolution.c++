class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i = 0; i < len; i++)
             dp[i][i] = true;

        int ret = 0;
        for(int i = len-1; i >= 0; i--)
        {
            for(int j = i; j < len; j++)
            {
                if(i == j)
                    ret++;
                else if(s[i] == s[j])
                {
                    if(j-i == 1)
                    {
                        ret++;
                        dp[i][j] = true;
                    }
                    else if(dp[i+1][i+1] && dp[i+1][j-1])
                    {
                        ret++;
                        dp[i][j] = true;
                    }
                }
            }
        }  
        return ret;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len2 = s.size();
        if(!len2)  return true;
        int len = t.size();
        if(!len)  return false;

        

        vector<vector<int>> dp(len2, vector<int>(len, 0));
        if(t[0] == s[0])
            dp[0][0] = 1;
        for(int i = 1; i < len; i++)
            if(t[i] == s[0])
                dp[0][i] = 1;
            else if(dp[0][i-1])
                dp[0][i] = 1;
        
        for(int i = 1; i < len2; i++)
        {
            if(s[i] == t[0])
                dp[i][0] = 1;
            else if(dp[i-1][0])
                dp[i][0] = 1;
            for(int j = 1; j < len; j++)
            {
                if(s[i] == t[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
          
        }

        return dp[len2-1][len-1] == len2;
    }
};

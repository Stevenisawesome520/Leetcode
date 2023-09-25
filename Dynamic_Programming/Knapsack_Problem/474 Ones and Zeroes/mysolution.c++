class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < strs.size(); i++)
        {
            int m2 = 0;
            int n2 = 0;
            for(int j = 0; j < strs[i].size(); j++)
                if(strs[i][j] == '0')
                    m2++;
                else
                    n2++;
            
            for(int j = m; j >= 0; j--)
            {
                for(int k = n; k >= 0; k--)
                {
                    if(j - m2 >= 0 && k - n2 >= 0)
                    {
                        dp[j][k] = max(dp[j][k], dp[j-m2][k-n2] + 1);
                    }
                    if(i == strs.size()-1 && j == m && k == n)
                        return dp[m][n];
                }
            }
        }
        return dp[m][n];
    }
};

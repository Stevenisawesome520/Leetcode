class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2 * k, 0));
        int maxP = 0;
        for(int i = 0; i < 2 * k ; i+=2)
        {
            dp[0][i] = -prices[0];
        }
        for(int i = 1; i < len; i++)
        {
            for(int j = 0; j < 2*k; j++)
            {
                if(j == 0)
                    dp[i][j] = max(-prices[i], dp[i-1][j]);
                else
                {
                    if(j % 2)
                    {
                        dp[i][j] = max(dp[i-1][j], prices[i] + dp[i-1][j-1]);
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j], -prices[i] + dp[i-1][j-1]);
                    }
                }

                maxP = max(dp[i][j], maxP);
            }
            
        }
    return maxP;
    }
    
};

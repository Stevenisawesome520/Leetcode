class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(5));
        dp[0][0] = -prices[0]; //hold the stock transaction=0
        dp[0][1] = 0; //not hold the stock transaction=0

        dp[0][2] = -prices[0]; //hold the stock transaction=1
        dp[0][3] = 0;  //not hold the stock transaction=1

        dp[0][4] = 0; //not hold the stock transaction=2

        for(int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = dp[i-1][1];

            dp[i][2] = max(dp[i-1][2], dp[i-1][3]-prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][0]+prices[i]);

            dp[i][4] = max(dp[i-1][4], dp[i-1][2]+prices[i]);
        }

        return dp[len-1][4];
    }
};

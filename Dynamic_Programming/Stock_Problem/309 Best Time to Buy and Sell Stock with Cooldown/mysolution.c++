class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        //0 hold
        //1 not hold
        //2 cooldown

        vector<vector<int>> dp(len, vector<int>(3,0));
        dp[0][0] = -prices[0];

        for(int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i-1][2]-prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            dp[i][2] = max(dp[i-1][0] + prices[i-1], dp[i-1][1]);
        }        

        return max(dp[len-1][1], dp[len-1][2]);
    }
};

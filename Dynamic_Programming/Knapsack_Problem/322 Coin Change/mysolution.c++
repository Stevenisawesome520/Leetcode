class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        vector<int> dp(amount+1,100000);
        dp[0] = 0;
        for(int i = 1; i < amount+1; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);    
            }
        }
        if(dp[amount] == 100000)
            return -1;  
        return dp[amount];
    }
};

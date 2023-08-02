class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(sum/2+1, 0);
        for(int i = 0; i < stones.size(); i++)
        {
            for(int j = sum/2; j >=0; j--)
            {
                if(j - stones[i] >= 0)
                    dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 *  dp[sum/2];
    }
};

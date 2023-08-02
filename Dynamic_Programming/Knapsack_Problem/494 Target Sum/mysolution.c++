class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int count0 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(!nums[i])
                count0++;
        }
        target = abs(target);
        if((sum - target) % 2 || sum < target)
            return 0;
        if(sum == target)
            return 1 * (1<<count0);
        vector<int> dp((sum-target)/2 +1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            dp[0] = 1;
            for(int j = (sum-target)/2 - nums[i]; j >=0; j--)
            {
                if((j == 0 || dp[j]) && nums[i] != 0 )
                {
                    dp[j+nums[i]] = dp[j+nums[i]] + dp[j];
                }
            }
        }

        return dp[(sum-target)/2]*(1<<count0);
    }
};

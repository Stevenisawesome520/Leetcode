class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int maxLen = 1;
        vector<int> dp(len,1);
        for(int i = 1; i < len; i++)
        {
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] +1; 

            maxLen = max(dp[i], maxLen);
        }
        return maxLen;
    }
};

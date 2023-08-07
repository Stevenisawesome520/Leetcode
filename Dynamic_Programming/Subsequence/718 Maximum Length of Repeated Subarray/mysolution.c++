class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int maxLen = 0;
        vector<vector<int>> dp(size1, vector<int>(size2,0));
        for(int i = 0; i < size1; i++)
        {
            for(int j = 0; j < size2; j++)
            {
                if(i == 0 || j == 0)
                {
                    if(nums1[i] == nums2[j])
                    {
                        maxLen = max(maxLen, 1);
                        dp[i][j] = 1;
                    } 
                }
                else
                {
                    if(nums1[i] == nums2[j])
                    {
                        dp[i][j] = dp[i-1][j-1] + 1;
                        maxLen = max(maxLen, dp[i][j]);
                    }
                }
            }
        }      
        return maxLen;  
    }
};

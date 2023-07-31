class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int maxLen = 1;
        int sign;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(i == 0)
            {
                if(nums[i+1] - nums[i] > 0)
                {
                    maxLen++;
                    sign = 1;
                }
                else if(nums[i+1] - nums[i] < 0)
                {
                    maxLen++;
                    sign = -1;                   
                }
                else
                {
                    sign = 0;
                }
            }
            else if(sign == 1)
            {
                if(nums[i+1] - nums[i] < 0)
                {
                    maxLen++;
                    sign = -1;                   
                }
            }
            else if(sign == -1)
            {
                if(nums[i+1] - nums[i] > 0)
                {
                    maxLen++;
                    sign = 1;                   
                }
            }
            else
            {
                if(nums[i+1] - nums[i] > 0)
                {
                    maxLen++;
                    sign = 1;
                }
                else if(nums[i+1] - nums[i] < 0)
                {
                    maxLen++;
                    sign = -1;                   
                }
                else
                {
                    sign = 0;
                }
            }
        }
        
        return maxLen;
    }
};

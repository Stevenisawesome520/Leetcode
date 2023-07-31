class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] + nums[i] > nums[i])
            {
                nums[i] = nums[i-1] + nums[i];
            }
            maxNum = max(maxNum,  nums[i]);
        }
        return maxNum;
    }
};

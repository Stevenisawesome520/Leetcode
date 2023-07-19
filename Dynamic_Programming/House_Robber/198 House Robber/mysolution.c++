//Time Limit Exceeded
/*
class Solution {
public:
    int rob(vector<int>& nums, int idx)
    {
        if(idx+2 > nums.size()-1)
            return nums[idx];
        if(idx+3 > nums.size()-1)
            return rob(nums, idx+2) + nums[idx];
        return max(rob(nums, idx+2), rob(nums, idx+3))+nums[idx];

    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(rob(nums, 0),rob(nums, 1));
    }
};
*/

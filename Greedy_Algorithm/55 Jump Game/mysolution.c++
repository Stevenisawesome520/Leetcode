class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int right = nums[0];
      
        for(int i = 0; i <= right; i++)
        {
            if(nums[i] + i >= len)
                return true;
            else if(nums[i] + i > right)
            {
                right = nums[i] + i;
            }
        }
        if(right >= len-1)
            return true;
        return false;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<=1)
            return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0)
            return false;

        vector<int> combo(sum/2+1, 0);
        combo[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = sum/2; j >= 0; j--)
            {
                if(combo[j] && j+nums[i] <= sum/2)
                {
                    combo[j+nums[i]]=1;
                }
            }
            if(combo[sum/2])
                return true;
        }
        return false;
    }
};

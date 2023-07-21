class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 1;
        vector<int> lens(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    lens[i] = max(lens[i], lens[j]+1);
                    maxLen = max(maxLen, lens[i]);
                }
            }

        }
        return maxLen;
    }
};

//O(n^2)

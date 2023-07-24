class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        if(size == 1)
        {
            nums[size-1] *= nums[size-1];
            return nums;
        }
        if(nums[0] >=0 && nums[size-1] >=0)
        {
            for(int i = 0; i < size; i++)
            {
                nums[i] *= nums[i];
            }
            return nums;
        }
        if(nums[0] < 0 && nums[size-1] < 0)
        {
            for(int i = 0; i < size; i++)
            {         
                nums[i] *= nums[i];
            }
            reverse(nums.begin(),nums.end());
            return nums;
        }
        int idx = size-1;
        for(int i = 0; i < size - 1; i++)
        {
            if(nums[i] < 0 && nums[i+1] >=0)
            {
                idx = i+1;
            }
            nums[i] *= nums[i];
        }
       
        nums[size-1] *= nums[size-1];

        int j = idx - 1;
        while(j > -1 && idx < size)
        {
            if(nums[j] < nums[idx])
            {
                ans.push_back(nums[j--]);
            }
            else
            {
                ans.push_back(nums[idx++]);
            }
        }
        if(j > -1)
        {
            while(j > -1)
                ans.push_back(nums[j--]);
        }
        else if(idx < nums.size())
        {
            while(idx < nums.size())
                ans.push_back(nums[idx++]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int len = nums.size();
        if(len < 4)
            return ret;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < len - 3; i++)
        {
            for(int j = i + 1; j < len - 2; j++)
            {
                int left = j + 1;
                int right = len - 1;

                while(left < right)
                {
                    if(long(nums[left]) + long(nums[right]) > long(target) - long(nums[i]) - long(nums[j]))
                        right--;
                    else if(long(nums[left]) + long(nums[right]) < long(target) - long(nums[i]) - long(nums[j]))
                        left++;
                    else
                    {
                        vector<int> qua = {nums[i],  nums[j], nums[left], nums[right]};
                        ret.push_back(qua);
                        
                        while(left < right && nums[right] == qua[3])
                            right--;

                        while(left < right && nums[left] == qua[2])
                            left++;
                        //remove right lest
                    }
                }

                int temp = nums[j];
                while(j < len - 2 && nums[j+1] == temp)
                    j++;
                

            }

            
            int temp = nums[i];
            while(i < len - 3 && nums[i+1] == temp)
                i++;
        }

        return ret;
    }
};

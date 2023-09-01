class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int maxI = nums[0];
        int i = 0;
        int ans = 1;

        while(maxI < nums.size()-1)
        {
            int temp = maxI;
            while(i <= temp)
            {
                if(i + nums[i] > maxI)
                {
                    maxI = i + nums[i];
                }
                i++;
            }
            ans++;
        }
            
        return ans;
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(k && nums[i] < 0)
            {
                ans += -(nums[i]);
                k--;
            }
            else if(k && k%2)
            {
                if(i && abs(nums[i-1]) < nums[i])
                {
                    ans -= 2*abs(nums[i-1]);
                    ans += nums[i];
                }
                else
                    ans += -(nums[i]);
                k = 0;
            }
            else
            {
                ans += nums[i];
            }
                       
        }
        if(k%2)
            ans += 2*nums[nums.size()-1];

        return ans;
    }
};

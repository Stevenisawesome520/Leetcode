class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        if(len == 2)
            return max(nums[0], nums[1]);
            
        vector<int> first = nums;
        first[len-1] = 0;
        nums[0] = 0;

        vector<vector<int>> dp1(len, vector<int>(2, 0)); //0 take, 1 not take
        vector<vector<int>> dp2(len, vector<int>(2, 0));

        dp1[0][0] = first[0];
        dp1[1][0] = first[1];
        dp1[0][1] = 0;
        dp1[1][1] = first[0];

        dp2[0][0] = nums[0];
        dp2[1][0] = nums[1];
        dp2[0][1] = 0;
        dp2[1][1] = nums[0];


        for(int i = 2; i < len; i++)
        {
            dp1[i][0] = max({first[i] + dp1[i-1][1], first[i] + dp1[i-2][0], first[i] + dp1[i-2][1]});
            dp1[i][1] = max({dp1[i-1][0], dp1[i-1][1], dp1[i-2][0], dp1[i-2][1]});

            dp2[i][0] = max({nums[i] + dp2[i-1][1], nums[i] + dp2[i-2][0], nums[i] + dp2[i-2][1]});
            dp2[i][1] = max({dp2[i-1][0], dp2[i-1][1], dp2[i-2][0], dp2[i-2][1]});


        }
        return max({dp1[len-1][0], dp1[len-1][1],dp2[len-1][0],dp2[len-1][1]});
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = nums[0];
        int ans = 100001;
        queue<int> q;
        q.push(sum);
        for(int i = 1; i < nums.size(); i++)
        {
            if(sum >= target)
            {
                while( q.size() && (sum - q.front()) >= target)
                {
                    sum -= q.front();
                    q.pop();
                }
                ans = ans < q.size() ? ans : q.size();
                //ans = min(ans, q.size());

                sum -= q.front();
                q.pop();

                // sum += nums[i];
                // q.push(nums[i]);

                
            } 
            sum += nums[i];
            q.push(nums[i]); 
            // else
            // {
            //     sum += nums[i];
            //     q.push(nums[i]);
            // }
           
        }
        if(sum >= target)
        {
            while( q.size() && (sum - q.front()) >= target)
            {
                sum -= q.front();
                q.pop();
            }
            ans = ans < q.size() ? ans : q.size();
        }
        
        return ans == 100001 ? 0 : ans;
    }
};

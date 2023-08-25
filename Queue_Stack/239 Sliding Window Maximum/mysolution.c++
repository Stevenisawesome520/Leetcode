class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;

        deque<int> q;
        q.push_back(0);
        
        for(int i = 1; i < k; i++)
        {
            if(nums[i] > nums[q.front()])
                q.push_front(i);
            else if(nums[i] >= nums[q.back()])
            {
                while(q.size() && nums[i] >= nums[q.back()])
                    q.pop_back();

                q.push_back(i);
            }
            else if(nums[i] <= nums[q.back()])
            {
                q.push_back(i);
            }
        }
        ret.push_back(nums[q.front()]);

        for(int i = k; i < nums.size(); i++)
        {
            if(nums[i] >nums[q.front()])
                q.push_front(i);
            else if(nums[i] >= nums[q.back()])
            {
                while(q.size() && nums[i] >= nums[q.back()])
                    q.pop_back();

                q.push_back(i);
            }
            else if(nums[i] < nums[q.back()])
            {
                q.push_back(i);
            }

            while(q.front() <= i-k)
                q.pop_front();
            
            ret.push_back(nums[q.front()]);
        }

        return ret;
    }
};

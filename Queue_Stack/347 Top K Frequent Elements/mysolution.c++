class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;

        priority_queue<pair<int, int> > pq;
        int len = nums.size();
        int count = 1;
        for(int i = 1; i < len; i++)
        {
            if(nums[i] != nums[i-1])
            {
                pq.push(make_pair(count, nums[i-1]));
                count = 1;
            }
            else
            {
                count++;
            }
        }   

        pq.push(make_pair(count, nums[len-1]));

        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

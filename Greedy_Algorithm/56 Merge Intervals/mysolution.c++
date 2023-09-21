class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0]; 
    }
        
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0][0];
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            if(intervals[i][1] < intervals[i+1][0])
            {
                ans.push_back(vector<int>{left, intervals[i][1]});
                left = intervals[i+1][0];
            }
            else
            {
                if(intervals[i+1][1] < intervals[i][1])
                    intervals[i+1][1] = intervals[i][1];
            }
                 
        }

        ans.push_back(vector<int>{left, intervals[intervals.size() - 1][1]});

        return ans;
    }
};

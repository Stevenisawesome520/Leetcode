class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            if(intervals[i][1] > intervals[i+1][0])
            {
                ans++;
                if(intervals[i][1] < intervals[i+1][1])
                    intervals[i+1][1] = intervals[i][1];
            }
        }

        return ans;
    }
};

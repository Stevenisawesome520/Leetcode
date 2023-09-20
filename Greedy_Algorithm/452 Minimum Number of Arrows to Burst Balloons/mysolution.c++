class Solution {
public:


    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];     
    }

    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        for(int i = 0; i < points.size();)
        {
            ans++;
            int j = i + 1;
            while(j < points.size())
            {

                if(points[i][1] < points[j][0])
                    break;

                points[i][0] = max(points[i][0], points[j][0]);
                points[i][1] = min(points[i][1], points[j][1]);

                j++;
            }
            i = j;
        }

        return ans;
    }
};

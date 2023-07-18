class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for(int j = 0, i = 0; (j < s.size()) && (i < g.size()); i++)
        {
            if(g[i] <= s[j])
            {
                ans++;
                j++;
            }
            else
            {
                while(j < s.size() && g[i] > s[j])
                    j++;
                i--;
            }

            
        }
        return ans;
    }
};

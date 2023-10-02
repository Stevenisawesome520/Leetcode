class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> tab;
        int ans = 0;
        int maxN = height[0];
        tab.push_back(height[0]);

        for(int i = 1; i < height.size(); i++)
        {
            if(height[i] <= tab[tab.size()-1])
                tab.push_back(height[i]);
            else
            {
                if(maxN <= height[i])
                {
                    while(tab.size())
                    {
                        ans += maxN - tab[tab.size() - 1];
                        tab.pop_back();
                    }
                    tab.push_back(height[i]);
                    maxN = height[i];
                }
                else
                {
                    for(int j = tab.size()-1; j >=0 && tab[j] < height[i]; j--)
                    {
                        ans += height[i] - tab[j];
                        tab[j] = height[i];
                    }
                    tab.push_back(height[i]);
                }
            }
        }

        return ans;
    }
};

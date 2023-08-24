class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        unordered_map<int, int> tab;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            tab[nums[i]] = i;
        }

        for(int i = 0; i < len-2; i++)
        {
            for(int j = i + 1; j < len-1; j++)
            {
                if(tab.find(-nums[i]-nums[j]) != tab.end() && tab[-nums[i]-nums[j]] > i && tab[-nums[i]-nums[j]] > j)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(-nums[i]-nums[j]);
                    ret.push_back(temp);

                    i = tab[nums[i]];
                    j = tab[nums[j]];
                }
            }
        }
        return ret;       
    }
};

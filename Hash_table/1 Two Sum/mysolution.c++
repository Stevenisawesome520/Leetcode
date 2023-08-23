class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tab;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
        {
            if(tab.find(target-nums[i]) == tab.end())
                tab[nums[i]] = i;
            else
            {
                ret.push_back(i);
                ret.push_back(tab[target-nums[i]]);
                break;
            }
        }
        return ret;
    }
};

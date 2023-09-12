class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backT(vector<int>& nums, int idx)
    {
        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++)
        {
            int tempN = nums[i];

            temp.push_back(nums[i]);
            backT(nums, i + 1);
            temp.pop_back();

            if(nums[i] == tempN)
            {
                while(i < nums.size() && nums[i] == tempN)
                    i++;
                i--;
            }
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backT(nums, 0);

        return ans;
    }
};

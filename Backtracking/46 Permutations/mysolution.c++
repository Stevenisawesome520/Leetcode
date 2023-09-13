class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void backT(vector<int>& nums)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
            
        for(int i = temp.size(); i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            swap(nums[i], nums[temp.size()-1]);
            backT(nums);
            swap(nums[temp.size()-1], nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backT(nums);
        return ans;
    }
};

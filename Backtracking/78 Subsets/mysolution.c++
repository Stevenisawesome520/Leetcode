class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backT(vector<int>& nums, int idx)
    {
        temp.push_back(nums[idx]);

        for(int i = idx + 1; i < nums.size(); i++)
        {
            backT(nums, i);
            ans.push_back(temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(temp);
        
        for(int i = 0; i < nums.size(); i++)
        {
            vector <int>().swap(temp);
            backT(nums, i);
            ans.push_back(temp);
        }

        return ans;
    }
};

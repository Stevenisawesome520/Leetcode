class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    
    void combine(vector<int>& candidates, int target, int index)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0)
            return;

        for(int i = index; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            combine(candidates, target-candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combine(candidates, target, 0);
        return ans;
    }
};

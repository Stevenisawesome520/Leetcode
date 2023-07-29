class Solution {
public:
    vector<vector<int>> ans;
    vector<int> coms;
    void cal(int start, int k, int n)
    {
        if(k == 0)
        {
            if(n == 0)
                ans.push_back(coms);

            k++;
            return;

        }
        for(int i = start; i <= 9; i++)
        {
            coms.push_back(i);
            cal(i+1, k-1, n-i);
            coms.pop_back();
        }
        k++;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        cal(1, k, n);
        return ans;
    }
};

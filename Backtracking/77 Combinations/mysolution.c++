class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> v;
    void c(int idx, int k)
    {
        if(!k)
        {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }  
        for(int i = idx; i < v.size()-k+1;i++)
        {
            temp.push_back(v[i]);
            c(i+1, k - 1);
        }
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        for(int i = 1; i <= n; i++)
            v.push_back(i);
        c(0, k);
        return ans;
    }
};

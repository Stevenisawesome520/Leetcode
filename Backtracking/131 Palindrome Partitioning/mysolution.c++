class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool ispalindrome(string s)
    {
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(s[i] != s[len-1-i])
                return false;
        }
        return true;
    }

    void backtracking(string s, int start_index)
    {
        if(start_index == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 1; i <= s.size() - start_index; i++)
        {
            string tempS = s.substr(start_index, i);
            if(ispalindrome(tempS))
            {
                temp.push_back(tempS);
                backtracking(s, start_index+i);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};

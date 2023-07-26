class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        ans.push_back(s[0]);
        for(int i = 1; i < s.size(); i++)
        {
            if(ans.empty() || ans[ans.size()-1] != s[i])
                ans.push_back(s[i]);
            else if(ans[ans.size()-1] == s[i])
                ans.pop_back();
        }

        return ans;
    }  
};

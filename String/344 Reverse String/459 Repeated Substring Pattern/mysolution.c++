class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sub, temp;
        sub.push_back(s[0]);
        for(int i = 1, j = 0; i < s.size(); i++)
        {
            if(s[i] != sub[0] && temp.empty())
            {
                sub.push_back(s[i]);
            }
            else if(s[i] == sub[j % sub.size()])
            {
                temp.push_back(s[i]);
                if(i == s.size()-1 && (j % sub.size() == sub.size()-1))
                    return true;
                j++;
            }
            else if(s[i] != sub[j % sub.size()])
            {
                sub.push_back(temp[0]);
                temp.clear();
                i = sub.size()-1;
                j=0;
            }
        }
        return false;
    }
};

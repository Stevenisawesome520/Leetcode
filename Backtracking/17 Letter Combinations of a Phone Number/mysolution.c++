class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans;
    string temp;
    string stringD;

    void comb(int idx)
    {
        if(idx == stringD.size())
        {
            if(!temp.empty())
            {
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        for(int i = 0; i < pad[stringD[idx] - '0'].size(); i++)
        {
            temp.push_back(pad[stringD[idx] - '0'][i]);
            comb(idx+1);
        }
        temp.pop_back();
    }
    vector<string> letterCombinations(string digits) {
        stringD = digits;
        comb(0);
        return ans;
    }
};

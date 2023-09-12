class Solution {
public:
    string temp;
    vector<string> ans;
    int count = 0;
    string eraseDot(string s)
    {
        if(s.size())
        {
            while(s.size() && s[s.size()-1] != '.')
                s.pop_back();

            if(s.size())
                s.pop_back();
        }
        

        return s;
    }
    void backT(string s, int start, int end)
    {
        
        if(start + end - 1 > s.size()-1)
            return;
        string sstr = s.substr(start, end);
        if((stoi(sstr) >0 && stoi(sstr) <= 255 && sstr[0] != '0') || sstr == "0")
        {
            count++;
            if(count == 4 && start + end != s.size() )
            {
                count--;
                return;
            }
            temp += sstr;
            temp.push_back('.');
        }
        else
        {
            return;
        }

        if(count == 4 && start + end == s.size())
        {
            temp.pop_back();
            ans.push_back(temp);
            temp = eraseDot(temp);
            temp.push_back('.');
            count--;
            return;
        }
        else if(start + end == s.size())
        {
            temp.pop_back();
            temp = eraseDot(temp);
            temp.push_back('.');
            count--;
            return;
        }

        
        for(int i = 3; i > 0; i--)
        {
            backT(s, start+end, i);
        }
        temp.pop_back();
        temp = eraseDot(temp);
        temp.push_back('.');
        count--;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 3)
            for(int i = 3; i > 0; i--)
            {
                temp = "";
                count = 0;
                backT(s, 0, i);
            }

        return ans;
    }
};

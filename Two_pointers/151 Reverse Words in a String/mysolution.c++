class Solution {
public:
    string reverseWords(string s) {
        // s.erase(0, s.find_first_not_of(" "));
        // s.erase(s.find_last_not_of(" ")+1);
        reverse(s.begin(), s.end());
        int i = 0;
        int j = 0;
        while(j < s.size())
        {
            if(s[i] == ' ')
            {
                int count = 0;
                while(s[j++] == ' ')
                {
                    count++;
                }
                s.erase(i,count);
                j = i;
            }
            else if(s[j] == ' ')
            {
                reverse(s.begin() + i, s.begin() + j);
                i = ++j;
            }
            else
            {
                j++;
            }
        }
        if(s[s.size()-1] == ' ')
            s.erase(s.size()-1,1);
        reverse(s.begin()+i, s.end());
        return s;

    }
};

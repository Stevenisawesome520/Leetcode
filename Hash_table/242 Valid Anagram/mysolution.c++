class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> record;
        for(int i=0; i < s.size(); i++)
        {
            if(record.count(s[i]))
            {
                record[s[i]] += 1;
            }
            else
                record[s[i]] = 1;
        }

        for(int i=0; i < t.size(); i++)
        {
            if(record.count(t[i]))
            {
                record[t[i]] -= 1;
                if(record[t[i]] < 0)
                    return false;
            }
            else
                return false;
        }
        for(unordered_map<char, int>::iterator iter = record.begin(); iter!=record.end(); iter++)
            if(iter->second > 0)
                return false;
        return true;
    }
};

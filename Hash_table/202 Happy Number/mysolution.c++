class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        int temp = 0;
        unordered_map<int, int> record;
        for(;;)
        {
            temp = 0;
            for(int i = 0; i < s.size(); i++)
            {
                temp += (s[i]-'0') * (s[i]-'0');
            }
            if(temp == 1)
                return true;
            if(record[temp])
                return false;

            record[temp] = 1;

            s = to_string(temp);
        }
    }
};

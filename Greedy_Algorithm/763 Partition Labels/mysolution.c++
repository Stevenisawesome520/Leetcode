class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int pos[26] = {-1};
        int len = s.size();
        for(int i = 0; i < len; i++)
            pos[s[i] - 'a'] = i;
        
        int i = 0;
        int bound = pos[s[i] - 'a'];
        while(i < len)
        {
            bound = pos[s[i] - 'a'];
            int j = i + 1;
            while(j < len && j <= bound)
            {
                if(pos[s[j] - 'a'] > bound)
                    bound = pos[s[j] - 'a'];
                
                j++;
            }
            ans.push_back(j-i);
            i = j;
        }

        return ans;
    }
};

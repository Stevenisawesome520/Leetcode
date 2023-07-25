class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        vector<string> ans;
        for(int i = 0; i < words[0].size(); i++)
        {
            um1[words[0][i]] += 1;
            um2[words[0][i]] += 1;
        }

        for(int i = 1; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(um1.find(words[i][j]) != um1.end())
                {
                    um2[words[i][j]] = um2[words[i][j]] - 1;
                }
            }
            for(auto iter1 = um1.begin(), iter2 = um2.begin(); iter1 != um1.end(); iter1++, iter2++) 
            {
                if(iter2->second >= 0)
                {

                    iter1->second -= iter2->second;
                    
                }
                iter2->second = iter1->second;
            }
        }
        for(auto iter = um1.begin(); iter != um1.end(); iter++)
        {
            while(iter->second)
            {
                string s(1, iter->first);
                ans.push_back(s);
                iter->second -= 1;
            }
        }

        return ans;
    }
};

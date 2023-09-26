class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for(int i = 0; i <= s.size(); i++)
        {
            if(dp[i])
            {
                for(int j = 0; j < wordDict.size(); j++)
                {
                    if(s.substr(i, wordDict[j].size()) == wordDict[j])
                        dp[i+wordDict[j].size()] = true;
                }
            }
        }

        return dp[len];
    }
};

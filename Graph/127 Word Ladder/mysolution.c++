class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> umap;
        umap[beginWord] = true;
        unordered_map<string, vector<string>> umap2;

        int len = wordList.size();
        vector<string> temp;
        queue<string> nextStrs;
        for(int i = 0; i < len; i++)
        {
            int diff = 0;
            for(int j = 0; j < beginWord.size(); j++)
            {
                if(beginWord[j] != wordList[i][j])
                    diff++;
                if(diff > 1)
                    break;
            }
            if(diff == 1)
            {
                if(wordList[i] == endWord) return 2;
                temp.push_back(wordList[i]);
                nextStrs.push(wordList[i]);
            }
        }
        umap2[beginWord] = temp;
        for(int i = 0; i < len; i++)
        {
            vector<string>().swap(temp);
            for(int j = 0; j < len; j++)
            {
                if(i == j) continue;
                int diff = 0;
                for(int k = 0; k < beginWord.size(); k++)
                {
                    if(wordList[i][k] != wordList[j][k])
                        diff++;
                    if(diff > 1)
                        break;
                }
                if(diff == 1)
                {
                    temp.push_back(wordList[j]);
                }
            }
            umap2[wordList[i]] = temp;
        }
        
        int ans = 2;
        while(nextStrs.size())
        {
            int len = nextStrs.size();
            ans++;
            for(int i = 0; i < len; i++)
            {
                string word = nextStrs.front();
                nextStrs.pop();
                for(int j = 0; j < umap2[word].size(); j++)
                {
                    if(umap2[word][j] == endWord) return ans;

                    if(!umap[umap2[word][j]])
                    {
                        nextStrs.push(umap2[word][j]);
                        umap[umap2[word][j]] = true;
                    }
                    
                }
            }
            
        }
        return 0;


    }
};

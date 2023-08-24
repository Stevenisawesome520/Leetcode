class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> tab;

        for(int i = 0; i < magazine.size(); i++)
        {
            tab[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++)
        {
            if(tab[ransomNote[i]])
                tab[ransomNote[i]]--;
            else
                return false; 
        }
        return true;
    }
};

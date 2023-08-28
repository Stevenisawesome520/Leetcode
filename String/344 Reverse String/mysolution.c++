//Brute Force optimized
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for(int i=0; i < s.size()/2; i++)
        {
            temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }
    }
};


//KMP
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        vector<int> vec(len, 0);
        
        for(int i = 1, j = 0; i < len; i++)
        {
            while(j > 0 && s[i] != s[j])
                j--;
            
            if(s[i] == s[j])
                j++;

            vec[i] = j;
        }
        if(vec[len-1] < ceil(len/2.0))
            return false;
        
        // if(vec[len-1] == len/2)
        //     return true;

        for(int i = len - vec[len-1], j = 0; i < len; i++, j++)
        {
            if(s[i] != s[j % (len - vec[len-1])])
                return false;
            if(i == len-1 && j % (len - vec[len-1]) != len - vec[len-1]-1)
                return false;
        }

        return true;

        
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> front(len, 1);
        int ans = 0;
        for(int i = 1; i < len; i++)
        {
            if(ratings[i] > ratings[i-1])
                front[i] = front[i-1] + 1;   
        }

        for(int i = len-1; i >= 0; i--)
        {
            if(i == len - 1)
            {
                ans += front[i];
                front[i] = 1;
            }
            else
            {
                if(ratings[i] > ratings[i+1])
                {
                    ans += max(front[i], front[i+1] + 1);
                    front[i] = front[i+1] + 1;
                }
                else
                {
                    ans += front[i]; 
                    front[i] = 1;
                }
            }
            
        }

        return ans;
    }
};

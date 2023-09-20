class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[0] == b[0])
        {
            return a[1] > b[1];
        }   
        else
            return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        for(int i = people.size() - 2; i >= 0; i--)
        {
            if(people[i][1])
            {
                int j = people[i][1];
                int temp = i;
                while(j)
                {
                    swap(people[i], people[i + 1]);
                    i++;
                    j--;
                }
                i = temp;
            }
        }
        return people;

    }
};

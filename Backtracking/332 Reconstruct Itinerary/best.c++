class Solution {
public:
    unordered_map<string, multiset<string>> tab;
    vector<string> ans;

    void traverse(string airport)
    {

        while(tab[airport].size())
        {
            string str = *tab[airport].begin();
            tab[airport].erase(tab[airport].begin());
            traverse(str);
        }
        ans.push_back(airport);
        
        
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0; i < tickets.size(); i++)
        {
            tab[tickets[i][0]].insert(tickets[i][1]);
        }

        traverse("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

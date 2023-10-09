class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < edges.size(); i++)
        {
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < umap[2].size(); i++)
            cout << umap[2][i] << ' ';

        queue<int> que;
        unordered_set<int> uset;
        uset.insert(source);
        for(int i = 0; i < umap[source].size(); i++)
        {
            if(umap[source][i] == destination) return true;
            uset.insert(umap[source][i]);
            que.push(umap[source][i]);
        }

        while(que.size())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                int node = que.front();
                que.pop();
                for(int j = 0; j < umap[node].size(); j++)
                {
                    if(uset.find(umap[node][j]) == uset.end())
                    {
                        if(umap[node][j] == destination) return true;
                        uset.insert(umap[node][j]);
                        que.push(umap[node][j]);
                    }
                }
            }
        }
            
        
        return false;   
    }
};

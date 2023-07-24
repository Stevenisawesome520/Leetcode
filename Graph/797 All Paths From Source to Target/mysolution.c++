class Solution {
public:
    vector<vector<int>> out;
    vector<int> path = {0};
    void traverse(int idx, vector<vector<int>>& graph)
    {
        for(int i = 0; i < graph[idx].size(); i++)
        {
            if(graph[idx][i] == graph.size()-1)
            {
                path.push_back(graph[idx][i]);
                out.push_back(path);
                path.pop_back();
                continue;
            }
            path.push_back(graph[idx][i]);
            traverse(graph[idx][i], graph); 
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        traverse(0, graph);
        return out;
    }
};
